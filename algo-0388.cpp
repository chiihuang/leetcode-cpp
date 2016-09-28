class Solution {
public:
    
    static const int STATUS_LINE_START = 0;
    static const int FILENAME = 1;
    static const int INDENTATION = 2;
    static const int END = 3;
    stack<int> pump;
    int pumplen = 0;
    
    int status = STATUS_LINE_START;
    string filename = "";
    int namelen = 0;
    int level = 0;
    int isFile = false;
    
    int maxlen = 0;
    
    void reset(){
        namelen = 0;
        level = 0;
        isFile = false;
    }
    
    int getCurrentLengthAndSetLevel(){
        auto pump_level = pump.size();
        int ret = 0;
        if (pump_level < level) {
            ret = pumplen + namelen;
        } else {
            auto times = pump_level - level;
            for (int i = 0; i < times; i++) {
                pumplen -= pump.top();
                pump.pop();
            }
            ret = pumplen + namelen;
        }
        return ret;
    }

    void process(char c){
        switch(status){
            case STATUS_LINE_START:
                if (c == '\t') {
                    level++;
                    status = INDENTATION;
                } else { // \w
                    if (c == '.') isFile = true;
                    namelen++;
                    status = FILENAME;
                }
                break;
            case FILENAME:
                if (c == '\n') {
                    // big thing
                    auto curlen = getCurrentLengthAndSetLevel();
                    
                    if (isFile){
                        maxlen = curlen > maxlen ? curlen : maxlen;
                    } else {
                        pump.push(namelen + 1);
                        pumplen += namelen + 1;
                    }
                    
                    // turn back
                    reset();
                    status = STATUS_LINE_START;
                } else { // \w
                    if (c == '.') isFile = true;
                    namelen++;
                }
                break;
            case INDENTATION:
                if (c == '\t') { 
                    level++;
                } else { // \w
                    if (c == '.') isFile = true;
                    namelen++;
                    status = FILENAME;
                }
                break;
            case END:
                // conclude
                break;
        }
    }
    int lengthLongestPath(string input) {
        auto len = input.size();
        for(int i = 0; i < len; i++){
            // cout << input[i] << endl;
            process(input[i]);
        }
        status = END;
        
        auto curlen = getCurrentLengthAndSetLevel();
        
        if (isFile)
            maxlen = curlen > maxlen ? curlen : maxlen;
        return maxlen;
    }
};

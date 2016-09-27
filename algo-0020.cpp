class Solution {
public:
    bool isValid(string s) {
        stack<char> pump;
        int len = s.size();
        for(int i = 0; i < len; i++){
            auto c = s[i];
            switch(c){
                case '{':
                case '[':
                case '(':
                    pump.push(c);
                    break;
                case '}':
                case ']':
                case ')':
                    if (pump.empty())
                        return false;
                    else {
                        char p = pump.top();
                        pump.pop();
                        if ((p == '{' && c != '}')
                            || p == '[' && c != ']'
                            || p == '(' && c != ')')
                            return false;
                    }
                    break;
                default:
                    break;
            }
        }
        return pump.size() == 0;
    }
};

class Solution {
public:
    // pop one from deque to deque
    void restoreFront(deque<string> & dq, unordered_map<string, int> & hist){
        // pop last and put it back to hist
        auto front = dq.front();
        dq.pop_front();
        hist[front]++;
    }

    // restore histogram from deque
    void restoreHist(deque<string> & dq, unordered_map<string, int> & hist){
        while(!dq.empty()){
            auto f = dq.front();
            dq.pop_front();
            hist[f]++;
        }
    }
    bool isFulfilled(unordered_map<string, int> & hist){
        for(auto it = hist.begin(); it != hist.end(); ++it){
            if ((it->second) > 0){
                return false;
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        auto wlen = words[0].size();
        auto lsize = words.size();
        
        // init histogram
        unordered_map<string, int> hist;
        for(auto word : words){
            if (hist.find(word) == hist.end()){
                hist[word] = 1;
            } else {
                hist[word]++;
            }
        }
        
        struct Data{
            int pos;
            int mod;
            string word;
        };
        
        struct Compare {
          bool operator()(Data a, Data b){
              if (a.mod > b.mod) {
                  return true;
              } else if (a.mod < b.mod) {
                  return false;
              } else return a.pos > b.pos;
          }
        };
        priority_queue<Data, vector<Data>, Compare> omap;
        for(auto it = hist.begin(); it != hist.end(); it++){
            auto word = it->first;
            int beg = 0;
            while(true){
                auto idx = s.find(word, beg);
                if (idx != string::npos) {
                    Data d;
                    d.pos = idx;
                    d.mod = idx % wlen;
                    d.word = word;
                    omap.push(d);
                    beg = idx + 1;
                } else break;
            }
        }
        
        // dequeing and solving
        vector<int> ret; // position
        deque<string> dq; // current matched words
        int cur = 0;
        while(!omap.empty()){
            auto it = omap.top();
            omap.pop();
            auto pos = it.pos;
            auto word = it.word;
            
            // check interval
            if (pos - cur != wlen){
                restoreHist(dq, hist);
            }
            cur = pos;

            if (hist[word] > 0){
                hist[word]--;
                dq.push_back(word);
            } else {
               while(!dq.empty() && hist[word] <= 0){
                    restoreFront(dq, hist);
               }
                hist[word]--;
                dq.push_back(word);
            }

            if (isFulfilled(hist)){
                auto ans = pos - (lsize - 1 ) * wlen;
                ret.push_back(ans);
                restoreFront(dq, hist);
            }
        }
        
        return ret;
    }
};

class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> ocur;
        auto len = s.size();
        string ret;
        for(int i = 0; i < len; i++){
            if (ocur.find(s[i]) == ocur.end())
                ocur[s[i]] = 1;
            else
                ocur[s[i]] += 1;
        }

        set<char> used;
        deque<char> pump;
        for(int i = 0; i < len; i++){
            auto c = s[i];
            ocur[c]--;
            
            // found
            if (used.find(c) != used.end())
                continue;
                
            // if smaller => pop
            while(!pump.empty() && c < pump.back() && ocur[pump.back()] > 0){
                used.erase(pump.back());
                pump.pop_back();
            }
            
            pump.push_back(c);
            used.insert(c);
        }
        
        while(!pump.empty()){
            ret.push_back(pump.front());
            pump.pop_front();
        }
   
        return ret;
    }
};

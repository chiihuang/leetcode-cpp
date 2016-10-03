class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;
        for(auto s : strs){
            mp[sortStr(s)].insert(s);
        }
        vector<vector<string>> ret;
        for(auto m : mp){
            vector<string> group(m.second.begin(), m.second.end());
            ret.push_back(group);
        }
        return ret;
    }
private:
    string sortStr(string & str){
        int hist[26] = { 0 };
        for(auto c : str) hist[c - 'a']++;
        
        string ret(str.size(), 'a');
        int ptr = 0;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < hist[i]; j++)
                ret[ptr++] += i;
        }
        return ret;
    }
};

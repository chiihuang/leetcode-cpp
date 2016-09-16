class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        int arr_len = strs.size();
        if (arr_len <= 0) return "";
        int pt = 0;
        while(true){
            if (pt >= strs[0].size()) break;
            char c = strs[0][pt];
            bool brkn = false;
            for(int i = 1; i < arr_len; i++){
                if(pt >= strs[i].size() || c != strs[i][pt]) {
                    brkn = true;
                    break;
                }
            }
            if (brkn) break;
            ret.push_back(c);
            pt++;
        }
        return ret;

    }
};

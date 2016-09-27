class Solution {
public:
    vector<string> subgen(int left, int right){
        if (right <= 0 && left <= 0) return { "" };
        vector<string> ret;
        if (right > 0) {
            auto lret = subgen(left, right - 1);
            for(int i = 0; i < lret.size(); i++){
                ret.push_back(")" + lret[i]);
            }        
        }
        if (left > 0) {
            auto rret = subgen(left - 1, right + 1);
            for(int i = 0; i < rret.size(); i++){
                ret.push_back("(" + rret[i]);
            }
        }
        return ret;
    }
    vector<string> generateParenthesis(int n) {
        return subgen(n, 0);
    }
};

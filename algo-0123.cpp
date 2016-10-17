class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        int* elems = new int[len + 1];
        for(int i = 0; i < len + 1; i++) elems[i] = i;
        // center
        for(int i = 0; i < len; i++){
            // even
            for(int j = 1; i - j +1>= 0 && i + j < len && s[i - j+1] == s[i + j]; j++){
                elems[i + j + 1] = min(elems[i + j + 1], elems[i - j+1] + 1);
            }
            
            // odd
            for(int j = 0; i - j >= 0 && i + j < len && s[i - j] == s[i + j]; j++){
                elems[i + j + 1] = min(elems[i + j + 1], elems[i - j] + 1);
            }
        }
        return elems[len] - 1; // corner
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        int rep = 2 * numRows - 2; // corner: num = 1
        if (rep <= 0) return s;
        
        string ret(s.size(), ' ');
        int idx = 0;
        for(int i = 0; i < len; i+= rep){
            ret[idx++] = s[i];   
        }
        if (numRows > 2){
            for(int r = 1; r < numRows - 1; r++){
                for(int m1 = r, m2 = rep - r; m1 < len; m1 += rep, m2 += rep){
                    ret[idx++] = s[m1];
                    if (m2 >= len) break;
                    else ret[idx++] = s[m2];
                }
            }
        }
        for(int i = numRows - 1; i < len; i += rep){
            ret[idx++] = s[i];
        }
        return ret;
    }
};

// #include <cstdlib>

class Solution {
public:
    bool checkFollowing(string & num, long a, long b, int start){
        // next
        auto c = a + b;
        auto len = num.size();
        while(start < len){
            if (num.find(to_string(c), start) != start)
                return false;
            start += floor(log10(c)) + 1;
            // next round
            auto t = b;
            b = c;
            c = t + c;
        }
        return true;
    }
    bool isAdditiveNumber(string num) {
        int len = num.size();
        if (len < 3) return false;
        
        for(int i = 1; i < len - 1; i++) {
            for(int j = 1; i + j < len; j++) {
                if (('0' != num[i] || j < 2)
                    && ('0' != num[0] || i < 2)
                    && checkFollowing(num,
                    atol(num.substr(0, i).c_str()),
                    atol(num.substr(i, j).c_str()),
                    i + j )) return true;
            }
        }
        return false;
    }
};

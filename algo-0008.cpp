class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        int ret = 0;
        int sign = 1;
        
        bool startFlag = false;
        
        int INTMAX = pow(2, 31) - 1;
        int INTMIN = -pow(2, 31);
        for(int i = 0; i < len; i++){
            int d = str[i] - '0';
            // digit check
            if (d < 0 || d > 9) {
                if (!startFlag  && d == '-' - '0') {
                    sign = -1;
                    startFlag = true;
                } else if (!startFlag && d == '+' - '0') {
                    sign = 1;
                    startFlag = true;
                } else if (!startFlag && d == ' ' - '0'){
                    // pass
                } else {
                    return ret;
                }
            } else {
                startFlag = true;
                // overflow check
                if (sign > 0){
                    if (ret > (INTMAX - d) / 10) return INTMAX;
                } else {
                    if (ret < (INTMIN - sign * d) / 10) return INTMIN;
                }
                ret = ret * 10 + sign * d;
            }
        }
        return ret;
    }
};

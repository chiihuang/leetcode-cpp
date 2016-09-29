class Solution {
public:
    int divide(int dividend, int divisor) {
        long dvd = dividend;
        long dvs = divisor;
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        
        dvd = abs(dvd);
        dvs = abs(dvs);
        
        long quotiant = 0;
        
        while(dvd >= dvs) {
            long shift = 1;
            long shifted_dvs = dvs;
            while(dvd >= (shifted_dvs << 1)){
                shifted_dvs <<= 1;
                shift <<= 1;
            }

            dvd -= shifted_dvs;
            quotiant +=  shift;
        }
        
        long answer = sign * quotiant;

        return answer > INT_MAX ? INT_MAX : answer;
    }
};

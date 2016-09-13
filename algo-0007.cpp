class Solution {
public:
    int reverse(int x) {
        bool negative = x < 0 ? true : false;
        if (negative && x < -(pow(2, 31) - 1)) return 0;
        long abs_x = negative ? -x : x;
        long ret = 0;
        long MAX = negative ? pow(2, 31) : pow(2, 31) - 1;
        do {
            long r = abs_x % 10;
            long q = abs_x / 10;
            
            // overflow check
            double left = ((double) MAX - r) / 10;
            if (ret > left) return 0;
            
            ret = ret * 10 + r;
            abs_x = q;
        }while(abs_x > 0);
        
        return negative ? -ret : ret;
    }
};

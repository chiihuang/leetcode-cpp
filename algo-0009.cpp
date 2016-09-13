class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int temp_x = x;
        int reverse = 0;
        do {
           int r = temp_x % 10;
           int q = temp_x / 10;
           int result = reverse * 10 + r;
           if ((result - r) / 10 != reverse) return false; // overflow
           reverse = result;
           temp_x = q;
        }while(temp_x > 0);
        
        return reverse == x;
    }
};

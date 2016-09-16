class Solution {
public:
    string intToRoman(int num) {
        string ret;
        while(num >= 1000) {
            ret.push_back('M');
            num -= 1000;
        }

        if (1000 - num <= 100){
            num -= 900;
            ret.push_back('C');
            ret.push_back('M');
        }
        
        if (500 - num <= 100 && num < 500) {
            ret.push_back('C');
            ret.push_back('D');
            num -= 400;
        } else if (num >= 500) {
            ret.push_back('D');
            num -= 500;
        }

        while(num >= 100){
            ret.push_back('C');
            num -= 100;
        }
        
        if (100 - num <= 10) {
            ret.push_back('X');
            ret.push_back('C');
            num -= 90;
        }
        
        if (50 - num <= 10 && num < 50) {
            ret.push_back('X');
            ret.push_back('L');
            num -= 40;
        } else if (num >= 50) {
            ret.push_back('L');
            num -= 50;
        }
        
        while(num >= 10){
            ret.push_back('X');
            num -= 10;
        }

        if (10 - num <= 1) {
            num -= 9;
            ret.push_back('I');
            ret.push_back('X');
        }
        if (5 - num <= 1 && num < 5) {
            ret.push_back('I');
            ret.push_back('V');
            num -= 4;
        } else if (num >= 5) {
            ret.push_back('V');
            num -= 5;
        }
        
        while(num > 0){
            ret.push_back('I');
            num--;
        }

        return ret;
    }
};

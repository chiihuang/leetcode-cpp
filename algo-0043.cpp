class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string ret = "";
        int sum = 0;
        // i  = digits
        for(int i = 0; i < num1.size() + num2.size() - 1; i++){
            for(int j = 0; j < num1.size(); j++){
                int k = i - j;
                if (k < num2.size()){
                    int d1 = num1[num1.size() - 1 - j] - '0';
                    int d2 = num2[num2.size() - 1 - k] - '0';
                    sum += d1 * d2;
                }
            }
            char base = (char) '0' + sum % 10;
            sum = sum / 10;
            ret.insert(0, 1, base);
        }
        
        if (sum > 0) ret.insert(0, 1, (char) '0' + sum);
        return ret;
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        vector<string> ret;
        vector<string> subret;
        unordered_map<char, vector<char>> code = {
            { '2', {'a', 'b', 'c'} },
            { '3', {'d', 'e', 'f'} },
            { '4', {'g', 'h', 'i'} },
            { '5', {'j', 'k', 'l'} },
            { '6', {'m', 'n', 'o'} },
            { '7', {'p', 'q', 'r', 's'} },
            { '8', {'t', 'u', 'v'} },
            { '9', {'w', 'x', 'y', 'z'} },
            { '0', {' '} }
        };
        if (len == 0) return ret;
        if (len > 1) subret = letterCombinations(digits.substr(1, len - 1));
        for (auto candidate : code[digits[0]]) {
            if (len <= 1){
                ret.push_back(string (1, candidate));
            } else {
                for (auto sub : subret) {
                    ret.push_back(candidate + sub);
                }
            }
        }
        return ret;
    }
};

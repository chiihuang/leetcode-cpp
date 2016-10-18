//   a  b  a  c  a
//  -1 -1  0 -1  0


// j = -1
//   a  c  a  b  a

//   0 -1  0  1  2

class Solution {
public:
    int* buildTable(string& s){
        int len = s.size();
        int* pre = new int[len];
        for(int i = 0; i < len; i++){
            if(i == 0) { pre[i] = -1; continue; }
            int j = pre[i - 1];
            while(j >= 0 && s[i] != s[j + 1]){
                j = pre[j];
            }
            if (s[i] != s[j + 1]) pre[i] = -1;
            else pre[i] = j + 1;
        }
        return pre;
    }
    string shortestPalindrome(string s) {
        int len = s.size();
        auto rev = s;
        reverse(rev.begin(), rev.end());
        int* pre = buildTable(s);
        int j = -1;
        for(int i = 0; i < rev.size(); i++){
            while(j >= 0 && rev[i] != s[j + 1]){
                j = pre[j];
            }
            if (rev[i] == s[j + 1]) j += 1;
            else j = -1;
        }
        return rev.substr(0, len - j - 1) + s;
    }
};

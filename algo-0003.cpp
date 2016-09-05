class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128];
        fill_n(hash, 128, -1);
        int max = 0;
        int low = 0;
        int len = s.size();
        for(int i = 0; i < len; i++){
            // needs to cut short
            if (hash[s[i]] >= low) {
                int sublen = i - low;
                max = sublen > max ? sublen : max;
                low = hash[s[i]] + 1;
            } else{
                int sublen = i - low + 1;
                max = sublen > max ? sublen : max;
            }
            hash[s[i]] = i;
        }
        return max;
    }
};

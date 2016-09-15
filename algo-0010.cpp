class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        bool dp[m + 1][n + 1]; // dp[i][j] means p[0:i] matches p[0;j]
        dp[0][0] = true;
        for (int i = 1; i < m + 1; i++){
            dp[i][0] = false;
        }
        for (int j = 1; j < n + 1; j++){
            dp[0][j] = dp[0][j - 1] && ('*' == p[j - 1] || (j < n && '*' == p[j]));
        }
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                dp[i][j] = false;
                if (dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]))
                    dp[i][j] = true;
                if (dp[i][j - 1] && '*' == p[j - 1])
                    dp[i][j] = true;
                if (dp[i][j - 1] && j < n && '*' == p[j])
                    dp[i][j] = true;
                if (dp[i - 1][j] && j < n && '*' == p[j] && ((s[i - 1] == p[j - 1]) || '.' == p[j - 1]))
                    dp[i][j] = true;
            }
        }
        return dp[m][n];
    }
};

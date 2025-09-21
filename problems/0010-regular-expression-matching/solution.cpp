class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, s, p, dp);
    }

    bool solve(int i, int j, const string& s, const string& p, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];
        int n = s.size(), m = p.size();

        if (j == m) return dp[i][j] = (i == n); 

        bool firstMatch = (i < n) && (p[j] == s[i] || p[j] == '.');

        if (j+1 < m && p[j+1] == '*') {
            bool ans = solve(i, j+2, s, p, dp) || (firstMatch && solve(i+1, j, s, p, dp));
            return dp[i][j] = ans;
        } else {
            bool ans = firstMatch && solve(i+1, j+1, s, p, dp);
            return dp[i][j] = ans;
        }
    }
};

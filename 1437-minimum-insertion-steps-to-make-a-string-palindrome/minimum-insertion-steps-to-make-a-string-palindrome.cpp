class Solution {
   public:
    int dp[1001][1001];

    int solve(string &s, int i, int j) {
        // Base case
        if (i >= j) return 0;

        // Already computed
        if (dp[i][j] != -1) return dp[i][j];

        // Characters match
        if (s[i] == s[j]) {
            return dp[i][j] = solve(s, i + 1, j - 1);
        }

        // Characters don't match
        return dp[i][j] = 1 + min(solve(s, i + 1, j), solve(s, i, j - 1));
    }
    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.size() - 1);
    }
};

class Solution
{
public:
    vector<vector<int>> dp;

    int solve(string &s, string &t, int i, int j)
    {
        // Successfully formed target
        if (j == t.size())
            return 1;

        // Source exhausted
        if (i == s.size())
            return 0;

        // Already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if (s[i] == t[j])
        {
            return dp[i][j] =
                solve(s, t, i + 1, j + 1) +   // Take
                solve(s, t, i + 1, j);        // Skip
        }

        // Characters don't match
        return dp[i][j] = solve(s, t, i + 1, j);
    }

    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        dp.resize(n, vector<int>(m, -1));

        return solve(s, t, 0, 0);
    }
};
class Solution {
public:
    int solve(string &s1, string &s2, int i, int j,
              vector<vector<int>> &dp)
    {
        // s1 finished
        if (i == s1.size())
        {
            int sum = 0;
            while (j < s2.size())
            {
                sum += s2[j];
                j++;
            }
            return sum;
        }

        // s2 finished
        if (j == s2.size())
        {
            int sum = 0;
            while (i < s1.size())
            {
                sum += s1[i];
                i++;
            }
            return sum;
        }

        // Already computed
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if (s1[i] == s2[j])
        {
            return dp[i][j] =
                solve(s1, s2, i + 1, j + 1, dp);
        }

        // Delete from s1
        int deleteFromS1 =
            s1[i] + solve(s1, s2, i + 1, j, dp);

        // Delete from s2
        int deleteFromS2 =
            s2[j] + solve(s1, s2, i, j + 1, dp);

        return dp[i][j] =
            min(deleteFromS1, deleteFromS2);
    }

    int minimumDeleteSum(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(s1, s2, 0, 0, dp);
    }
};
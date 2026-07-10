class Solution {
public:
    vector<vector<int>> dp;

    int solve(string &word1, string &word2, int i, int j)
    {
        // Base Cases
        if(i == word1.size())
            return word2.size() - j;

        if(j == word2.size())
            return word1.size() - i;

        // Already Computed
        if(dp[i][j] != -1)
            return dp[i][j];

        // Characters Match
        if(word1[i] == word2[j])
            return dp[i][j] = solve(word1, word2, i + 1, j + 1);

        // Insert
        int insert = 1 + solve(word1, word2, i, j + 1);

        // Delete
        int del = 1 + solve(word1, word2, i + 1, j);

        // Replace
        int replace = 1 + solve(word1, word2, i + 1, j + 1);

        return dp[i][j] = min({insert, del, replace});
    }

    int minDistance(string word1, string word2)
    {
        dp.resize(word1.size(), vector<int>(word2.size(), -1));

        return solve(word1, word2, 0, 0);
    }
};
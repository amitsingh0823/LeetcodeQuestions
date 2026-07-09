class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int pos, int stepsLeft, int arrLen,
              vector<vector<int>>& dp) {

        if (pos < 0 || pos >= arrLen)
            return 0;

        if (stepsLeft == 0)
            return pos == 0;

        if (dp[pos][stepsLeft] != -1)
            return dp[pos][stepsLeft];

        long long stay = solve(pos, stepsLeft - 1, arrLen, dp);

        long long left = solve(pos - 1, stepsLeft - 1, arrLen, dp);

        long long right = solve(pos + 1, stepsLeft - 1, arrLen, dp);

        return dp[pos][stepsLeft] =
               (stay + left + right) % MOD;
    }

    int numWays(int steps, int arrLen) {

         int maxPos = min(arrLen - 1, steps);

        vector<vector<int>> dp(maxPos + 1,
                               vector<int>(steps + 1, -1));

        return solve(0, steps, arrLen, dp);
    }
};
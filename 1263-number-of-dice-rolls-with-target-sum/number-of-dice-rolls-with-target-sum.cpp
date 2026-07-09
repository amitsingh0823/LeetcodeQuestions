class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int diceLeft, int k, int target, vector<vector<int>>& dp) {

        if (diceLeft == 0 && target == 0)
            return 1;

        if (diceLeft == 0)
            return 0;

        if (target < 0)
            return 0;

        if (dp[diceLeft][target] != -1)
            return dp[diceLeft][target];

        long long ways = 0;

        for (int face = 1; face <= k; face++) {
            ways = (ways + solve(diceLeft - 1, k, target - face, dp)) % MOD;
        }

        return dp[diceLeft][target] = ways;
    }

    int numRollsToTarget(int n, int k, int target) {

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return solve(n, k, target, dp);
    }
};
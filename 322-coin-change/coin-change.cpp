class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& coins, int idx, int amount) {

        // Base Case
        if (amount == 0)
            return 0;

        if (idx == coins.size())
            return INT_MAX;

        // Already computed
        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int take = INT_MAX;

        // Take current coin (stay at same index)
        if (amount >= coins[idx]) {

            int temp = solve(coins, idx, amount - coins[idx]);

            if (temp != INT_MAX)
                take = temp + 1;
        }

        // Skip current coin
        int skip = solve(coins, idx + 1, amount);

        return dp[idx][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        dp.assign(n, vector<int>(amount + 1, -1));

        int ans = solve(coins, 0, amount);

        return (ans == INT_MAX) ? -1 : ans;
    }
};
class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& prices, int index, bool canBuy) {
        // Base Case
        if (index >= prices.size())
            return 0;

        // Already Computed
        if (dp[index][canBuy] != -1)
            return dp[index][canBuy];

        // We can buy
        if (canBuy) {
            int buy = -prices[index] + solve(prices, index + 1, false);

            int skip = solve(prices, index + 1, true);

            return dp[index][canBuy] = max(buy, skip);
        }
        // We have a stock
        else {
            int sell = prices[index] + solve(prices, index + 2, true);

            int hold = solve(prices, index + 1, false);

            return dp[index][canBuy] = max(sell, hold);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp.resize(n, vector<int>(2, -1));

        return solve(prices, 0, true);
    }
};
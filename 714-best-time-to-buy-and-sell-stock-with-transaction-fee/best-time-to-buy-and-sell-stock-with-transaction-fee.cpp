class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& prices, int fee, int index, bool canBuy)
    {
        // Base Case
        if (index == prices.size())
            return 0;

        // Already Computed
        if (dp[index][canBuy] != -1)
            return dp[index][canBuy];

        // We can buy
        if (canBuy)
        {
            int buy = -prices[index] +
                      solve(prices, fee, index + 1, false);

            int skip = solve(prices, fee, index + 1, true);

            return dp[index][canBuy] = max(buy, skip);
        }
        // We have a stock
        else
        {
            int sell = prices[index] - fee +
                       solve(prices, fee, index + 1, true);

            int hold = solve(prices, fee, index + 1, false);

            return dp[index][canBuy] = max(sell, hold);
        }
    }

    int maxProfit(vector<int>& prices, int fee)
    {
        int n = prices.size();

        dp.resize(n, vector<int>(2, -1));

        return solve(prices, fee, 0, true);
    }
};
class Solution {
public:
    // vector<vector<vector<int>>> dp;
    int dp[100001][2][101];

    int solve(vector<int>& prices, int index, bool canBuy, int maxTransaction) {

        if (index == prices.size() || maxTransaction == 0)
            return 0;

        if (dp[index][canBuy][maxTransaction] != -1)
            return dp[index][canBuy][maxTransaction];

        if (canBuy) {

            int buy = -prices[index] +
                      solve(prices, index + 1, false, maxTransaction);

            int skip = solve(prices, index + 1, true, maxTransaction);

            return dp[index][canBuy][maxTransaction] = max(buy, skip);

        } else {

            int sell = prices[index] +
                       solve(prices, index + 1, true, maxTransaction - 1);

            int hold = solve(prices, index + 1, false, maxTransaction);

            return dp[index][canBuy][maxTransaction] = max(sell, hold);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // dp.resize(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        memset(dp, -1, sizeof(dp));

        return solve(prices, 0, true, k);
    }
};
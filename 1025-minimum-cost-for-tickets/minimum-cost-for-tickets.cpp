class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& days, vector<int>& costs, int idx, int validTill) {

        if (idx == days.size())
            return 0;

        if (dp[idx][validTill] != -1)
            return dp[idx][validTill];

        // Current travel day is already covered
        if (days[idx] <= validTill) {
            return dp[idx][validTill] = solve(days, costs, idx + 1, validTill);
        }

        int oneDay =
            costs[0] + solve(days, costs, idx + 1, min(365, days[idx]));

        int sevenDay =
            costs[1] + solve(days, costs, idx + 1, min(365, days[idx] + 6));

        int thirtyDay =
            costs[2] + solve(days, costs, idx + 1, min(365, days[idx] + 29));

        return dp[idx][validTill] = min({oneDay, sevenDay, thirtyDay});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n = days.size();

        dp.assign(n, vector<int>(366, -1));

        return solve(days, costs, 0, 0);
    }
};
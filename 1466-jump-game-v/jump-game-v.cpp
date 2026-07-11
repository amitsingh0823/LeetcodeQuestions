class Solution {
public:
    int n;
    vector<int> dp;

    int solve(vector<int>& arr, int i, int d) {

        if (dp[i] != -1)
            return dp[i];

        int ans = 1;

        // Jump to the left
        for (int j = i - 1; j >= max(0, i - d) && arr[j] < arr[i]; j--) {
            ans = max(ans, 1 + solve(arr, j, d));
        }

        // Jump to the right
        for (int j = i + 1; j <= min(n - 1, i + d)&& arr[j] < arr[i]; j++) {
            ans = max(ans, 1 + solve(arr, j, d));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {

        n = arr.size();
        dp.resize(n, -1);

        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(arr, i, d));
        }

        return ans;
    }
};
class Solution {
public:
    int n;
    int dp[10001];

    int solve(vector<int>& nums, int idx) {

        // Reached last index
        if (idx >= n - 1)
            return 0;

        // Already computed
        if (dp[idx] != -1)
            return dp[idx];

        int ans = INT_MAX;

        // Try every possible jump
        for (int jump = 1; jump <= nums[idx]; jump++) {

            int temp = solve(nums, idx + jump);

            if (temp != INT_MAX)
                ans = min(ans, 1 + temp);
        }

        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) {

        n = nums.size();
        memset(dp, -1, sizeof(dp));

        return solve(nums, 0);
    }
};
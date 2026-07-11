class Solution {
public:
    int dp[10001];

    bool solve(vector<int>& nums, int index) {
        int n = nums.size();

        // Reached or crossed the last index
        if (index >= n - 1)
            return true;

        // Already computed
        if (dp[index] != -1)
            return dp[index];

        // Try every possible jump
        for (int jump = 1; jump <= nums[index]; jump++) {
            if (solve(nums, index + jump))
                return dp[index] = true;
        }

        return dp[index] = false;
    }

    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};
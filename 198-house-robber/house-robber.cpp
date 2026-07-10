class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& nums, int index)
    {
        // Base Case
        if (index >= nums.size())
            return 0;

        // Already Computed
        if (dp[index] != -1)
            return dp[index];

        // Rob current house
        int rob = nums[index] + solve(nums, index + 2);

        // Skip current house
        int skip = solve(nums, index + 1);

        // Store and return
        return dp[index] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);

        return solve(nums, 0);
    }
};
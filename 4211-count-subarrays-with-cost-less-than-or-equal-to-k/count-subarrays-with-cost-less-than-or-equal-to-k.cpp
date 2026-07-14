class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int> maxdq;
        deque<int> mindq;

        int left = 0;
        long long ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Maintain decreasing deque for maximum
            while (!maxdq.empty() && nums[maxdq.back()] <= nums[right])
                maxdq.pop_back();

            maxdq.push_back(right);

            // Maintain increasing deque for minimum
            while (!mindq.empty() && nums[mindq.back()] >= nums[right])
                mindq.pop_back();

            mindq.push_back(right);

            // Shrink window while invalid
            while (left <= right &&(long long)(nums[maxdq.front()] - nums[mindq.front()]) *(right - left + 1) >k) {

                if (maxdq.front() == left)
                    maxdq.pop_front();

                if (mindq.front() == left)
                    mindq.pop_front();

                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }
};
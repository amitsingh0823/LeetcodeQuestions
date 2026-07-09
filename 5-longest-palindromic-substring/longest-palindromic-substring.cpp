class Solution {
public:
   vector<vector<int>> dp;

    // Recursive + Memoization
    bool isPalindrome(string &s, int left, int right)
    {
        // Base Case
        if (left >= right)
            return true;

        // Already Computed
        if (dp[left][right] != -1)
            return dp[left][right];

        // Characters don't match
        if (s[left] != s[right])
            return dp[left][right] = false;

        // Check inner substring
        return dp[left][right] = isPalindrome(s, left + 1, right - 1);
    }
    string longestPalindrome(string s) {
         int n = s.size();
        int ans = 0;
        string lps;

        dp.assign(n, vector<int>(n, -1));

        // Iterate over all possible starting indices
        for (int start = 0; start < n; start++)
        {
            // Iterate over all possible ending indices
            for (int end = start; end < n; end++)
            {
                if (isPalindrome(s, start, end)){
                    int result=end-start+1;
                    if (result>=ans){
                        ans=result;
                        lps=s.substr(start,end - start + 1);
                    }
                }
                    
            }
        }

        return lps;
    }
};
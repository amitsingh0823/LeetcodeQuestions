class Solution {
public:
    int ans = 0;

    // -1 = not computed
    //  0 = false
    //  1 = true
    vector<vector<int>> dp;

    bool isPalindrome(string &s, int left, int right)
    {
        // Base case
        if (left >= right)
            return true;

        // Already computed
        if (dp[left][right] != -1)
            return dp[left][right];

        // Characters don't match
        if (s[left] != s[right])
            return dp[left][right] = false;

        // Recurse for inner substring
        return dp[left][right] = isPalindrome(s, left + 1, right - 1);
    }

    // Recursively replace inner loop
    void solveEnd(string &s, int start, int end)
    {
        if (end == s.size())
            return;

        if (isPalindrome(s, start, end))
            ans++;

        solveEnd(s, start, end + 1);
    }

    // Recursively replace outer loop
    void solveStart(string &s, int start)
    {
        if (start == s.size())
            return;

        solveEnd(s, start, start);

        solveStart(s, start + 1);
    }

    int countSubstrings(string s)
    {
        int n = s.size();

        dp.assign(n, vector<int>(n, -1));

        solveStart(s, 0);

        return ans;
    }
};
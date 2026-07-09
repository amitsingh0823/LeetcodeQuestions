class Solution {
public:
    string str1, str2;
    vector<vector<int>> dp;

    int solve(int i, int j) {

        if (i == str1.size())
            return dp[i][j] = str2.size() - j;

        if (j == str2.size())
            return dp[i][j] = str1.size() - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (str1[i] == str2[j])
            return dp[i][j] = 1 + solve(i + 1, j + 1);

        return dp[i][j] = 1 + min(solve(i + 1, j), solve(i, j + 1));
    }

    string shortestCommonSupersequence(string s1, string s2) {

        str1 = s1;
        str2 = s2;

        int m = str1.size();
        int n = str2.size();

        dp.assign(m + 1, vector<int>(n + 1, -1));
        solve(0, 0); // Fill DP

        return build();
    }

    string build() {

        string ans;

        int i = 0;
        int j = 0;

        while (i < str1.size() && j < str2.size()) {

            if (str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            } else {

                // Take the direction with smaller SCS length
                if (dp[i + 1][j] <= dp[i][j + 1]) {
                    ans += str1[i];
                    i++;
                } else {
                    ans += str2[j];
                    j++;
                }
            }
        }

        while (i < str1.size())
            ans += str1[i++];

        while (j < str2.size())
            ans += str2[j++];

        return ans;
    }
};
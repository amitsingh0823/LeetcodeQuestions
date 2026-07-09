class Solution {
public:
    const int MOD = 1e9 + 7;

    unordered_map<char, vector<char>> graph;
    unordered_map<char, vector<long long>> dp;

    long long solve(char curr, int remaining) {

        // Only one character left to place (the current vowel itself)
        if (remaining == 1)
            return 1;

        // Already computed
        if (dp[curr][remaining] != -1)
            return dp[curr][remaining];

        long long ans = 0;

        for (char next : graph[curr]) {
            ans = (ans + solve(next, remaining - 1)) % MOD;
        }

        return dp[curr][remaining] = ans;
    }

    int countVowelPermutation(int n) {

        // Graph
        graph['a'] = {'e'};
        graph['e'] = {'a', 'i'};
        graph['i'] = {'a', 'e', 'o', 'u'};
        graph['o'] = {'i', 'u'};
        graph['u'] = {'a'};

        // DP Initialization
        dp['a'] = vector<long long>(n + 1, -1);
        dp['e'] = vector<long long>(n + 1, -1);
        dp['i'] = vector<long long>(n + 1, -1);
        dp['o'] = vector<long long>(n + 1, -1);
        dp['u'] = vector<long long>(n + 1, -1);

        long long ans = 0;

        ans = (ans + solve('a', n)) % MOD;
        ans = (ans + solve('e', n)) % MOD;
        ans = (ans + solve('i', n)) % MOD;
        ans = (ans + solve('o', n)) % MOD;
        ans = (ans + solve('u', n)) % MOD;

        return ans;
    }
};
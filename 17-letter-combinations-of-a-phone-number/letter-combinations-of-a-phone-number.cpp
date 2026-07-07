class Solution {
private:
    void solve(string digit, string output, int i,
               vector<string>& ans, string mapping[]) {

        // Base case
        if (i >= digit.length()) {
            ans.push_back(output);
            return;
        }

        int num = digit[i] - '0';
        string value = mapping[num];

        for (int j = 0; j < value.length(); j++) {
            solve(digit, output + value[j], i + 1, ans, mapping);
        }
    }

public:
    vector<string> letterCombinations(string digit) {

        vector<string> ans;

        if (digit.empty())
            return ans;

        string mapping[10] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solve(digit, "", 0, ans, mapping);

        return ans;
    }
};
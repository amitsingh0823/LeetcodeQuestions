class Solution {
public:
    bool solve(vector<int>& arr, int idx, vector<bool>& visited) {

        if (idx < 0 || idx >= arr.size())
            return false;

        if (visited[idx])
            return false;

        if (arr[idx] == 0)
            return true;

        visited[idx] = true;

        return solve(arr, idx + arr[idx], visited) ||
               solve(arr, idx - arr[idx], visited);
    }

    bool canReach(vector<int>& arr, int start) {

        vector<bool> visited(arr.size(), false);

        return solve(arr, start, visited);
    }
};
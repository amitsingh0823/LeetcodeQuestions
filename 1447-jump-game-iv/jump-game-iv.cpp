class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if (n == 1)
            return 0;

        unordered_map<int, vector<int>> mp;

        // Store all indices for each value
        for (int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);

        queue<pair<int,int>> q;
        vector<bool> visited(n, false);

        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {

            auto [idx, steps] = q.front();
            q.pop();

            if (idx == n - 1)
                return steps;

            // Left
            if (idx - 1 >= 0 && !visited[idx - 1]) {
                visited[idx - 1] = true;
                q.push({idx - 1, steps + 1});
            }

            // Right
            if (idx + 1 < n && !visited[idx + 1]) {
                visited[idx + 1] = true;
                q.push({idx + 1, steps + 1});
            }

            // Same value jumps
            if (mp.count(arr[idx])) {
                for (int next : mp[arr[idx]]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push({next, steps + 1});
                    }
                }

                // Important optimization
                mp.erase(arr[idx]);
            }
        }

        return -1;
    }
};
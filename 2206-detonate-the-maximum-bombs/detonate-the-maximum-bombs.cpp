class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int& cnt) {
        vis[node] = 1;
        cnt++;

        for (int next : adj[node]) {
            if (!vis[next]) {
                dfs(next, adj, vis, cnt);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();

        vector<vector<int>> adj(n);

        // Build directed graph
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (i == j) continue;

                long long dx = (long long)bombs[i][0] - bombs[j][0];
                long long dy = (long long)bombs[i][1] - bombs[j][1];

                long long dist = dx * dx + dy * dy;

                long long radius =
                    (long long)bombs[i][2] * bombs[i][2];

                if (dist <= radius) {
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 0;

        // Try detonating every bomb first
        for (int i = 0; i < n; i++) {

            vector<int> vis(n, 0);
            int cnt = 0;

            dfs(i, adj, vis, cnt);

            ans = max(ans, cnt);
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        // lets start by building the adjacency matrix
        vector<vector<int>> adj(n);
        for (auto it : invocations) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        
        vector<bool> vis_sus(n, false);
        queue<int> q_sus;
        q_sus.push(k);
        vis_sus[k] = true;
        while (!q_sus.empty()) {
            int node = q_sus.front();
            q_sus.pop();
            for (auto it : adj[node]) {
                if (!vis_sus[it]) {
                    vis_sus[it] = true;
                    q_sus.push(it);
                }
            }
        }

        vector<bool> vis(n, false);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!vis_sus[i]) {
                q.push(i);
                vis[i] = true;
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }

        bool can_remove = true;
        for (int i = 0; i < n; i++) {
            if (vis_sus[i] && vis[i]) {
                can_remove = false;
                break;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (can_remove && vis_sus[i] == 1) {
                continue;
            } else {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
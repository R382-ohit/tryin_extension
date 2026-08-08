class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }
        // pushing {time,node} into the priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        while (!pq.empty()) {
            int node = pq.top().second;
            int t = pq.top().first;
            pq.pop();

            if (t > dis[node])
                continue;

            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;

                if (t + wt < dis[v]) {
                    dis[v] = t + wt;
                    pq.push({dis[v], v});
                }
            }
        }
        int res = *max_element(dis.begin()+1, dis.end());
        return res == INT_MAX ? -1 : res;
    }
};
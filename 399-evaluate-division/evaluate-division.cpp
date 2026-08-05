class Solution {
public:
    double dfs(string u, string v,
               unordered_map<string, unordered_map<string, double>>& mpp,
               unordered_set<string>& visited) {
        if (u == v)
            return 1.0;
        visited.insert(u);

        for (auto& neighbour : mpp[u]) {
            string next = neighbour.first;
            double wt = neighbour.second;
            if (visited.find(next) == visited.end()) {
                double subRes = dfs(next, v, mpp, visited);
                if (subRes != -1.0) {
                    return wt * subRes;
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> mpp;
        vector<double> ans;
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double weight = values[i];
            mpp[u][v] = weight;
            mpp[v][u] = 1.0 / weight;
        }

        int m = queries.size();
        for (int i = 0; i < m; i++) {
            string u = queries[i][0];
            string v = queries[i][1];
            if (mpp.find(u) == mpp.end() || mpp.find(v) == mpp.end()) {
                ans.push_back(-1.0000);
                continue;
            }
            unordered_set<string> visited;
            ans.push_back(dfs(u, v, mpp, visited));
        }
        return ans;
    }
};
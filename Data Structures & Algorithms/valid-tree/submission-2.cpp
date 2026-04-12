class Solution {
    unordered_set<int> visit;
    vector<vector<int>> adj;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() < n - 1) {
            return false;
        }

        adj.resize(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        if (!dfs(0, -1)) {
            return false;
        }

        return visit.size() == n;
    }

    bool dfs(int idx, int parent) {
        if (visit.count(idx)) {
            return false;
        }
        
        visit.insert(idx);
        for (int nei : adj[idx]) {
            if (nei == parent) {
                continue;
            }
            if (!dfs(nei, idx)) {
                return false;
            }
        }
        return true;
    }
};

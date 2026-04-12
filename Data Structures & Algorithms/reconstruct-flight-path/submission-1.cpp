class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for (auto& ticket : tickets) {
            adj[ticket[0]];
        }

        for (auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        for (auto& [_, tickets] : adj) {
            sort(tickets.begin(), tickets.end());
        }

        vector<string> ret = {"JFK"};
        dfs("JFK", ret, adj, tickets.size() + 1);
        return ret;
    }

private:
    bool dfs(const string& src, vector<string>& ret, unordered_map<string, vector<string>>& adj, int targetLen) {
        if (ret.size() == targetLen) {
            return true;
        }

        if (adj.find(src) == adj.end()) {
            return false;
        }

        vector<string> temp = adj[src];
        for (int i = 0; i < temp.size(); ++i) {
            string v = temp[i];
            adj[src].erase(adj[src].begin() + i);
            ret.push_back(v);
            if (dfs(v, ret, adj, targetLen)) return true;
            adj[src].insert(adj[src].begin() + i, v);
            ret.pop_back();
        }

        return false;
    }
};

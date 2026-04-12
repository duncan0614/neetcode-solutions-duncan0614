class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;

        for (auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }

        vector<string> ret;
        dfs("JFK", ret, adj);
        reverse(ret.begin(), ret.end());
        return ret;
    }

private:
    void dfs(const string& src, vector<string>& ret, unordered_map<string, multiset<string>>& adj) {
        while (!adj[src].empty()) {
            auto it = adj[src].begin();
            string next = *it;
            adj[src].erase(it);
            dfs(next, ret, adj);
        }
        ret.push_back(src);
    }
};

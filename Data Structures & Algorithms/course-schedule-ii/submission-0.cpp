class Solution {
    unordered_map<int, vector<int>> crsMap;
    unordered_set<int> visiting;
    unordered_set<int> cycle;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            crsMap[i] = {};
        }

        for (const auto& preq : prerequisites) {
            crsMap[preq[0]].push_back(preq[1]);
        }

        vector<int> ret;
        
        for (int course = 0; course < numCourses; course++) {
            if (!dfs(course, ret)) {
                return {};
            }
        }

        return ret;
    }

    bool dfs(int crs, vector<int>& ret) {
        if (cycle.count(crs)) {
            return false;
        }
        if (visiting.count(crs)) {
            return true;
        }

        cycle.insert(crs);
        if (crsMap.count(crs)) {
            for (int pre : crsMap[crs]) {
                if (!dfs(pre, ret)) {
                    return false;
                }
            }
        }
        
        cycle.erase(crs);
        visiting.insert(crs);
        ret.push_back(crs);
        return true;
    }
};

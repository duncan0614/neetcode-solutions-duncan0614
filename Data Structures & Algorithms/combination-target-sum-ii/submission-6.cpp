class Solution {
public:
    set<vector<int>> ret;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<int> subset;
       sort(candidates.begin(), candidates.end());
       dfs(candidates, target, 0, subset, 0);
       return vector<vector<int>>(ret.begin(), ret.end());
    }
private:
    void dfs(vector<int>& candidates, int target, int index, vector<int>& subset, int total) {
        if (target == total) {
            ret.insert(subset);
            return;
        }

        if (total > target || index == candidates.size()) {
            return;
        }

        subset.push_back(candidates[index]);
        dfs(candidates, target, index + 1, subset, total + candidates[index]);
        subset.pop_back();

        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            index++;
        }
        dfs(candidates, target, index + 1, subset, total);
        return;
    }
};

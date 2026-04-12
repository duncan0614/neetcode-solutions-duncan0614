class Solution {
public:
    vector<vector<int>> ret;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<int> subset;
       sort(candidates.begin(), candidates.end());
       dfs(candidates, target, 0, subset, 0);
       return ret; 
    }
private:
    void dfs(vector<int>& candidates, int target, int index, vector<int>& subset, int total) {
        if (target == total and find(ret.begin(), ret.end(), subset) == ret.end()) {
            ret.push_back(subset);
            return;
        }

        if (total > target || index == candidates.size()) {
            return;
        }

        subset.push_back(candidates[index]);
        dfs(candidates, target, index + 1, subset, total + candidates[index]);
        subset.pop_back();
        dfs(candidates, target, index + 1, subset, total);
        return;
    }
};

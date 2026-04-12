class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> pick(nums.size(), false);
        vector<int> subset;
        dfs(nums, subset, pick);
        return ret;
    }

private:
    void dfs(vector<int>& nums, vector<int>& subset, vector<bool>& pick) {
        if (subset.size() == nums.size()) {
            ret.push_back(subset);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!pick[i]) {
                subset.push_back(nums[i]);
                pick[i] = true;
                dfs(nums, subset, pick);
                subset.pop_back();
                pick[i] = false;
            }
        }
        
        return;
    }

};

class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        dfs(nums, subset, target, 0);
        return ret;
    }

private:
    void dfs(vector<int>& nums, vector<int>& subset, int target, int index) {
        if (target == 0) {
            ret.push_back(subset);
            return;
        }

        if (target < 0 || index >= nums.size()) {
            return;
        }   

        subset.push_back(nums[index]);
        dfs(nums, subset, target - nums[index], index);

        subset.pop_back();
        dfs(nums, subset, target, index + 1);
        
        return;
    }
};

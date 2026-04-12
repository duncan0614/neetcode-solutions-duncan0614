class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, subset);
        return ret;
    }

private:
    void dfs(vector<int>& nums, int index, vector<int>& subset) {
        if (index >= nums.size()) {
            ret.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        dfs(nums, index + 1, subset);
        subset.pop_back();

        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
            index++;
        }

        dfs(nums, index + 1, subset);
        return;
    }
};

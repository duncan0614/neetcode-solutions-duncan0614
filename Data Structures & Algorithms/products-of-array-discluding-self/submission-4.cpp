class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numsCount = nums.size();
        vector<int> ret(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++){
            ret[i] = ret[i-1] * nums[i-1];
        }

        int prefix = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            ret[i] *= prefix;
            prefix *= nums[i];
        }

        return ret;
    }
};

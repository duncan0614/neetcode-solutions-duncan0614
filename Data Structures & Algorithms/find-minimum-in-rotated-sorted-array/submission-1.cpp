class Solution {
public:
    int findMin(vector<int> &nums) {
        int lIndex = 0, rIndex = nums.size() - 1, ret = nums[0];
        while (lIndex <= rIndex){
            if (nums[lIndex] < nums[rIndex]){
                ret = min(ret, nums[lIndex]);
                break;
            }

            int mid = (rIndex - lIndex) / 2 + lIndex;
            ret = min(ret, nums[mid]);

            if (nums[mid] >= nums[lIndex]){
                lIndex = mid + 1;
            }
            else{
                rIndex = mid - 1;
            }

        }

        return ret;
    }
};

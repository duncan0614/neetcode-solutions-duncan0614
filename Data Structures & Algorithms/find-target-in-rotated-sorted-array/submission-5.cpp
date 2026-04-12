class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lIndex = 0, rIndex = nums.size() - 1;

        while (lIndex <= rIndex){
            int mid = (rIndex - lIndex) / 2 + lIndex;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[lIndex] == target){
                return lIndex;
            }
            else if (nums[rIndex] == target){
                return rIndex;
            }
            else if (nums[mid] > nums[lIndex] && nums[lIndex] > nums[rIndex]){
                lIndex = mid + 1;
            }
            else{
                rIndex = mid - 1;
            }
        }

        return -1;
    }
};

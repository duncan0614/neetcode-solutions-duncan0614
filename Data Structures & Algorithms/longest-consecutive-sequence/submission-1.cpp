class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> countNums;
        int longest  = 0;

        for (int num : nums){

            if (!countNums[num]){
                countNums[num] = countNums[num - 1] + countNums[num + 1] + 1;
                countNums[num - countNums[num - 1]] = countNums[num];
                countNums[num + countNums[num + 1]] = countNums[num];
                longest = max(longest, countNums[num]);
            }
        }

        return longest;
    }
};

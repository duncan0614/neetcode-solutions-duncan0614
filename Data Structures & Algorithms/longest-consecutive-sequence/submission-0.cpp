class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> countNums(nums.begin(), nums.end());
        int longest  = 0;

        for (int num : nums){

            if (countNums.find(num - 1) == countNums.end()){
                int length = 0;

                while (countNums.find(num + length) != countNums.end()){
                    length += 1;
                }
                longest = max(longest, length);
            }
        }

        return longest;
    }
};

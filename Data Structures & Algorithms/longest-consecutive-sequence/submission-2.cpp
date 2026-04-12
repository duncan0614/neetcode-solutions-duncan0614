class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> countLongest;
        int longest = 0;

        for(int num : nums){

            if(!countLongest[num]){
                countLongest[num] = countLongest[num - 1] + countLongest[num + 1] + 1;
                countLongest[num - countLongest[num - 1]] = countLongest[num];
                countLongest[num + countLongest[num + 1]] = countLongest[num];
                longest = max(longest, countLongest[num]);
            }
        }

        return longest;
    }
};

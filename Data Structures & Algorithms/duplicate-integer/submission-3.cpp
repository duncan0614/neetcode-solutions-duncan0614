class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> checkSuccess;

        for (int num : nums){
            if (checkSuccess.find(num) != checkSuccess.end()) {
                return true;
            }
            checkSuccess.insert(num);
        }

        return false;
    }
};

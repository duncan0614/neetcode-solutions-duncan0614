class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        vector<int> ret;
        while (i < j){
            if(numbers[i] + numbers[j] > target){
                j--;
                continue;
            }
            else if(numbers[i] + numbers[j] < target){
                i++;
                continue;
            }

            ret.push_back(i+1);
            ret.push_back(j+1);
            break;
        }
        
        return ret;
    }
};

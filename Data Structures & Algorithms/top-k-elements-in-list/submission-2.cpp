class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCountMap;
        vector<vector<int>> countNum(nums.size() +1);
        for(int i = 0; i < nums.size(); i++){
            numCountMap[nums[i]] += 1;
        }

        for(auto& num : numCountMap){
            countNum[num.second].push_back(num.first);
        }

        vector<int> ret;
        for(int i = countNum.size() - 1; i > 0; --i){
            for(int n : countNum[i]){

                ret.push_back(n);
                if(ret.size() == k){
                    return ret;
                }
            }
            
        }

        return ret;
    }
};

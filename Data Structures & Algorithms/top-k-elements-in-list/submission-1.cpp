class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        //set the countnums size, plus 1 is because countnums[0] will not be used.
        vector<vector<int>> countnums(nums.size() + 1);
        for(int n : nums){
            countMap[n] += 1;
        }
        //Set the count and corresponding numbers to determine the frequency.
        for(const auto& num : countMap){
            countnums[num.second].push_back(num.first);
        }

        vector<int> ret;
        for(int i = countnums.size() - 1; i > 0; --i){
            for (int n : countnums[i]){
                
                //Fill the highest frequency into ret, until its size equal to k. 
                ret.push_back(n);
                if(ret.size() == k){
                    return ret;
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        bool zeroExist = false;
        int productNum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] != 0){
                productNum *= nums[i];
            }
            else{
                if (!zeroExist){
                    zeroExist = true;
                }
                else{
                    productNum = 0;
                }
            }
        }

        vector<int> ret;
        for (int i = 0; i < nums.size(); i++){
            if(!zeroExist){
                ret.push_back(productNum / nums[i]);
            }
            else{
                if (nums[i] != 0){
                    ret.push_back(0);
                }
                else{
                    ret.push_back(productNum);
                }
            }
            
        }

        return ret;
    }
};

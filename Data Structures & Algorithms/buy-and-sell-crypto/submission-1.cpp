class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int firstyBuy = prices[0];

        for (auto& price : prices){
            if (price <= firstyBuy){
                firstyBuy = price;
                continue;
            }
            else{
                ret = max(ret, price - firstyBuy);
            }
        }
        return ret;
    }
};

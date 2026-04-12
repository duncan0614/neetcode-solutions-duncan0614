class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int firstyBuy = prices[0];

        for (int i = 1; i < prices.size(); i++){
            if (prices[i] <= firstyBuy){
                firstyBuy = prices[i];
                continue;
            }
            else{
                int tempprice = prices[i] - firstyBuy;
                if (tempprice > ret){
                    ret = tempprice;
                }
            }
        }
        return ret;
    }
};

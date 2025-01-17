class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1){
            return 0;
        }

        int ans = 0;
        int minval = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > minval){
                ans = max(ans, prices[i] - minval);
            }
            else{
                minval = prices[i];
            }
        }
        return ans;
        
    }
};
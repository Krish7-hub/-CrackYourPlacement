class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] > mini){
                maxi = max(maxi, prices[i] - mini);
            }
            mini = min(mini, prices[i]);
        }
        if(maxi == INT_MIN){
            return 0;
        }
        return maxi;
    }
};
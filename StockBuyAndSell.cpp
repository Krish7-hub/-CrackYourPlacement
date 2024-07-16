int maximumProfit(vector<int> &prices){
   int min = prices[0];
   int maxProfit = 0;
   int n = prices.size();
   for(int i = 1; i < n; i++){
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        min = min(min, prices[i]);
   }
return maxProfit;
// T.C : O(n)
// S.C : O(1)

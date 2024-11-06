class StockSpanner {
public:
    vector<int>ans;
    StockSpanner() {
        ans = {};
    }
    
    int next(int price) {
        ans.push_back(price);
        int cnt = 1; 
        for(int i = ans.size()-2;  i >= 0; i--){
            if(ans[i] <= price){
                cnt++;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
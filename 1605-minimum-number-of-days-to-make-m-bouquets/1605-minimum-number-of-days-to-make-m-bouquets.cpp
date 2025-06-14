class Solution {
public:
    int find(int val, vector<int>& bloomDay, int k){
        int countDay = 0;
        int cnt = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= val){
                cnt++;
            }
            else{
                countDay += cnt/k;
                cnt = 0;
            }
        }
        countDay += cnt/k;
        return countDay;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long total = (long long)k * m;
        if(total > n){
            return -1;
        }
        long long low = *min_element(bloomDay.begin(), bloomDay.end());
        long long high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low  <= high){
            int mid = low + (high - low)/2;
            long long val = find(mid, bloomDay, k);
            if(val >= m){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
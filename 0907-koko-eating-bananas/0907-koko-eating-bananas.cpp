class Solution {
public:
    long long find(vector<int>& piles, long long val){
        long long cnt = 0;
        for(int i = 0; i < piles.size(); i++){
            cnt += ceil((double)piles[i]/(double)val);
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        long long n = piles.size();
        long long maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            if(piles[i] > maxi){
                maxi = piles[i];
            }
        }
        long long low = 1;
        long long  high = maxi;
        long long ans;
        while(low <= high){
            long long mid = low + (high - low)/2;
            long long val = find(piles, mid);
            if(val <= h){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return (int)low;
    }
};
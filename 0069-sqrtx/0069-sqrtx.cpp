class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        long low = 1, high = x;
        long  ans = 1;
        long mid;
        while(low <= high){
            mid = (low + high)/2;
            if((mid*mid) == x){
                return mid;
            }
            else if((mid*mid) > x){
                // ans = mid;
                high = mid - 1;
            } 
            else{
                ans = mid;
                low = mid + 1;
            } 
        }
        return ans;
    }
};
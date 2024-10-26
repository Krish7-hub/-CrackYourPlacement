class Solution {
public:
    double solve(double x, long n){
        long m = n;
        if(n < 0) {
            n = -n;
        }
        double ans = 1;
        while(n > 0){
            if(n % 2 == 1){
                ans = ans * x;
                n = n - 1;
            }
            else{
                n = n / 2;
                x = x * x;
            }
        }
        if(m < 0) return 1/ans;
        else return ans;
    }
    double myPow(double x, int n) {
       return solve(x, (long)n);
    }
};
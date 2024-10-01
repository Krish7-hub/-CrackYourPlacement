class Solution {
public:
    double findPow(double x, long n){
        if(n == 0) return 1;
        if(n < 0) return findPow(1/x, -n);
        if(n % 2 == 0) return findPow(x*x, n/2);
        return x*findPow(x*x, (n-1)/2);
    }

    double myPow(double x, int n) {
        return findPow(x, long(n));
    }
};
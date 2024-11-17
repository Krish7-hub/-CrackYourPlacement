class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0, n = cardPoints.size();
        for(int i = 0; i < k; i++){
            lsum += cardPoints[i];
        }
        int maxi = -1;
        for(int i = 1; i <= k; i++){
            maxi = max(maxi, lsum + rsum);
            lsum = lsum - cardPoints[k-i];
            rsum = rsum + cardPoints[n-i];
        }
        maxi = max(maxi, lsum + rsum);
        return maxi;

    }
};
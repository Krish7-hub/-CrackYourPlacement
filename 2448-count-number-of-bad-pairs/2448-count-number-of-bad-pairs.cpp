class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long ans = 0;
        long long cnt = 0;
        map<int, int>mpp;
        int val = 0 - nums[0];
        mpp[val]++;
        for(int i = 1; i < nums.size(); i++){
            int ind = i - nums[i];
            if(mpp.find(ind) != mpp.end()){
                cnt += mpp[ind];
            }
            mpp[ind]++;
        }
        
        long long totpair = n * (n-1)/2;
        ans = totpair - cnt;
        return ans;
        
    }
};
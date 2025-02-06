class Solution {
public:
    int nC2(int n){
        return n*(n-1)/2;
    }
    int tupleSameProduct(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int>freq;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int val = nums[i]*nums[j];
                freq[val]++;
            }
        }
        int count = 0;
        for(auto itr : freq){
            if(itr.second > 1){
                count += 8 * nC2(itr.second);
            }
        }
        return count;
    }
};
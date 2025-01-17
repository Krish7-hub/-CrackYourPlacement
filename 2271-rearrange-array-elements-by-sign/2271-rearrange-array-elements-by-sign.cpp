class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        // fill(ans, 0, nums.size());
        int posind = 0; 
        int negind = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                ans[posind] = nums[i];
                posind += 2;
            }
            else{
                ans[negind] = nums[i];
                negind += 2;
            }
        } 
        return ans;  
    }

};
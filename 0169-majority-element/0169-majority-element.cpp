class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int cnt = 1;
        int val = nums[0];
        int i = 1;
        while(i < nums.size()){
            if(val == nums[i]){
                cnt++;
            }
            else{
                cnt--;
                if(cnt < 0){
                    cnt = 1;
                    val = nums[i];
                }
            }
            i++;
        }
        return val;
        
    }
};
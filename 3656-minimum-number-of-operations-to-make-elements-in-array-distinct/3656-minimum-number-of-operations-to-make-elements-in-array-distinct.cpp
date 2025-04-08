class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int>arr(101, 0);
        int opr = 0;
        for(int i = nums.size()-1; i >= 0; i--){
            if(arr[nums[i]]){
                opr = (i+3)/3;
                return opr;
            }
            else{
                arr[nums[i]] = 1;
            }
        }
        return 0;
    }
};
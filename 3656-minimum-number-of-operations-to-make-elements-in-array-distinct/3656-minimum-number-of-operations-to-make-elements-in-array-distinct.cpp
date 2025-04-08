class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        map<int, int>mpp;
        int opr = 0;
        for(int i = n-1; i >= 0; i--){
            if(mpp.find(nums[i]) != mpp.end()){
                opr = (i+3)/3;
                break;
            }
            else{
                mpp[nums[i]]++;
            }
        }
        return opr;
    }
};
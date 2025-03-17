class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int>mpp;
        for(int i = 0; i < nums.size(); i++){
            // element -> count

            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            int cnt = it.second;
            if(cnt % 2 != 0){
                return false;
            }
        }
        return true;
    }
};
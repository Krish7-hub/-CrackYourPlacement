class Solution {
public:
   int findDuplicate(vector<int>&nums){
      int ans = -1;
        for(int i=0; i<nums.size(); i++){
            int index = abs(nums[i]);
            if(nums[index] < 0)
            {
                ans = index;
                break;
            }
            nums[index] *= -1;
        }
        return ans;
   }

   // Using Floyd Algorithm
    int slow = nums[0];
    int fast = nums[0];
    do{
       slow = nums[slow];
       fast = nums[nums[fast]];
    }while(slow != fast);

    fast = nums[0];
    while(slow != fast){
       slow = nums[slow];
       fast = nums[fast];
    }
    return slow;

};

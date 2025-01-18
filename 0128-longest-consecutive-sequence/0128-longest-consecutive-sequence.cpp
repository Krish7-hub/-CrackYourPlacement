class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int len = nums.size();
        if(len == 0){
            return 0;
        }
        int longest = 1;
        unordered_set<int>st;
        for(int i = 0; i < len; i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int cnt = 1; 
                int x = it;
                while(st.find(x + 1) != st.end()){
                    x = x + 1;
                    cnt += 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};
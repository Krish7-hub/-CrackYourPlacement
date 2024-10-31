class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int, int>mpp;
        for(auto it : nums2){
            while(!st.empty() && st.top() < it){
                mpp[st.top()] = it;
                st.pop();
            }
            st.push(it);
        }
        vector<int>ans(nums1.size(), -1);
        for(int i = 0; i < ans.size(); i++){
           auto itr = mpp.find(nums1[i]);
           if(itr != mpp.end()){
              ans[i] = itr->second;
           }
        }
        return ans;   
    }
};
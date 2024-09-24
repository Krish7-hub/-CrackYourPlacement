class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;
        for(int val : arr1){
            while(val > 0){
                st.insert(val);
                val /= 10;
            }
        }
        int result = 0;
        for(int val : arr2){
            while(!st.count(val) && val > 0){
                val /= 10;
            }
            if(val > 0){
                result = max(result, (int)log10(val) + 1);
            }
        }
        return result;
    }
};
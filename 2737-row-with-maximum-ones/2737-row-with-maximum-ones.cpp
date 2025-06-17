class Solution {
public:
    int lb(vector<int>vec, int n){
        sort(vec.begin(), vec.end());
        int low = 0;
        int high = n - 1;
        int ans = n;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(vec[mid] >= 1){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        int maxind = 0, maxval = 0;
        for(int i = 0; i < m; i++){
            int val = n - lb(mat[i], n);
            if(val > maxval){
                maxval = val;
                maxind = i;
            }
        }
        return {maxind, maxval};
        
    }
};
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        int ind = 0, val = 0;
        for(int i = 0; i < m; i++){
            int maxval = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    maxval++;
                }
            }
            if(maxval > val){
                val = maxval;
                ind = i;
            }
        }
        return {ind, val};
        
    }
};
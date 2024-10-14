class Solution {
public:
    
    void solve(int index, vector<vector<int>>&ans, vector<int>&output, vector<int>&candidates, int target){

        if(target == 0){
            ans.push_back(output);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            output.push_back(candidates[i]);
            solve(i+1, ans, output, candidates, target-candidates[i]);
            output.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>output;
        int index = 0;
        solve(index, ans, output, candidates, target);
        return ans;
    }
};
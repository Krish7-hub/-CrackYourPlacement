class Solution {
public:
    
    void findCombination(int index, int target, vector<vector<int>>&ans, vector<int>&output, vector<int>&candidates){

        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(output);
            }
            return;
        }

        if(candidates[index] <= target){
            output.push_back(candidates[index]);
            findCombination(index, target-candidates[index], ans, output, candidates);
            output.pop_back();
        }
        findCombination(index+1, target, ans, output, candidates);

    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>>ans;
        vector<int>output;
        int index = 0;
        findCombination(index, target, ans, output, candidates);
        return ans;

    }
};
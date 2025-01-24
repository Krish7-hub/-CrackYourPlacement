/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int& targetSum, int sum, vector<int>& path, vector<vector<int>>& ans){

        if(root == NULL){
            return;
        }
        int value = root -> val;
        path.push_back(value);
        sum += root -> val;
        // This is the leaf node.
        if(root -> left == NULL && root -> right == NULL){

            if(targetSum == sum){
                ans.push_back(path);
            }

            // Backtrack
            path.pop_back();
            return;

        }

        solve(root -> left, targetSum, sum, path, ans);
        solve(root -> right, targetSum, sum, path, ans);
        // backtrack
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>>ans;
        vector<int>path;
        solve(root, targetSum, 0, path, ans);
        return ans;
        
    }
};
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
    bool solve(TreeNode* root, int& targetSum, int sum){
        if(root == NULL){
            return false;
        }
        //This is the leaf node.
        if(root -> left == NULL && root -> right ==  NULL){
            sum += root -> val;
            if(sum == targetSum){
                return true;
            }
            else{
                return false;
            }
        }
        sum += root -> val;
        bool leftans = solve(root -> left, targetSum, sum);
        bool rightans = solve(root -> right, targetSum, sum);
        return leftans || rightans;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {

        bool ans = solve(root, targetSum, 0);
        return ans;
        
    }
};
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
    bool solve(TreeNode*& root, int& targetSum, int sum){
        if(root == NULL){
            return false;
        }
        sum += root -> val;
        // check if it is leaf node or not
        if(root -> left == NULL && root -> right == NULL){
            if(sum == targetSum){
                return true;
            }
            else {
                return false;
            }
        }
        bool leftAns = solve(root -> left, targetSum, sum);
        bool rightAns = solve(root -> right, targetSum, sum);
        return leftAns || rightAns;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {

        return solve(root, targetSum, 0);
        
    }
};
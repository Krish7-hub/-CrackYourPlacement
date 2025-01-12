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
    bool solve(TreeNode* root, int targetSum, int sum){

        if(root == NULL){
            return false;
        }

        // root is not null -> tree exist
        sum += root -> val;
        if(sum == targetSum){
            if(root -> left == NULL && root -> right == NULL){
                return true;
            }
        }

        bool leftTree = solve(root -> left, targetSum, sum);
        bool rightTree = solve(root -> right, targetSum, sum);

        return leftTree || rightTree;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {

        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;

    }
};
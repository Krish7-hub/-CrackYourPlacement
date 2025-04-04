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
    #define pni pair<TreeNode*, int>
    pni solve(TreeNode* root){
        // Base Case 
        if(root == NULL){
            return make_pair(nullptr, 0);
        }
        pni leftAns = solve(root -> left);
        pni rightAns = solve(root -> right);

        if(leftAns.second == rightAns.second){
            return {root, 1 + leftAns.second};
        }
        else if(leftAns.second > rightAns.second){
            return {leftAns.first, 1 + leftAns.second};
        }
        else{
            return {rightAns.first, 1 + rightAns.second};
        }
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pni res = solve(root);
        return res.first;
    }
};
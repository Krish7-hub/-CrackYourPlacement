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
    TreeNode* solve(TreeNode*& root, int& data){
        if(root == NULL){
            return NULL;
        }
        if(root -> val == data){
            return root;
        }
        if(data > root -> val){
            return solve(root -> right, data);
        }
        else{
            return solve(root -> left, data);
        }
        return NULL;
    }
    TreeNode* searchBST(TreeNode* root, int val) {

        TreeNode* ans = solve(root, val);
        return ans;
        
    }
};
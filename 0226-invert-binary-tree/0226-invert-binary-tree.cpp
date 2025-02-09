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
    TreeNode* invertTree(TreeNode* root) {

        if(root == NULL) return NULL;

        TreeNode* lefttree = invertTree(root -> left);
        TreeNode* righttree = invertTree(root -> right);
        TreeNode* temp = root -> left;
        root -> left = righttree;
        root -> right = temp;
        return root;
    }
};
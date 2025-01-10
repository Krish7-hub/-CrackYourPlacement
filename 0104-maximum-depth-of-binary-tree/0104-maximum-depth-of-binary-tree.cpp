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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftSubtreeHeight = maxDepth(root -> left);
        int rightSubtreeHeight = maxDepth(root -> right);
        int maxheight = max(leftSubtreeHeight, rightSubtreeHeight);
        int totalHeight = maxheight + 1;
        return totalHeight;
    }
};
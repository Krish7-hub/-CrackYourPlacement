/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL){
            return NULL;
        }

        // Case A both p and q lies in left subtree.
        if(p -> val < root -> val && q -> val < root -> val){
            TreeNode* leftAns = lowestCommonAncestor(root -> left, p, q);
            if(leftAns){
                return leftAns;
            }
        }
        // Case B both p and q lies in right subtree
        if(p -> val > root -> val && q -> val  > root -> val){
            TreeNode* rightAns = lowestCommonAncestor(root -> right, p, q);
            if(rightAns){
                return rightAns;
            }
        }
        // Case C p lies in left and q lies in right
        // Case D p lies in right and q lies in left
        return root;
    }
};
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
    int getHeight(TreeNode* root){

        if(root == NULL){
            return 0;
        }

        int leftHeight = getHeight(root -> left);
        int rightHeight = getHeight(root -> right);
        int maxHeight = max(leftHeight, rightHeight);
        int totalHeight = maxHeight + 1;
        return totalHeight;

    }
    bool isBalanced(TreeNode* root) {

        if(root == NULL){
            return true;
        }

        int lh = getHeight(root -> left);
        int rh = getHeight(root -> right);
        int absval = abs(lh - rh);
        bool status = (absval <= 1);
        
        bool leftst = isBalanced(root -> left);
        bool rightst = isBalanced(root -> right);

        if(status && leftst && rightst){
            return true;
        }
        else{
            return false;
        }
    }
};
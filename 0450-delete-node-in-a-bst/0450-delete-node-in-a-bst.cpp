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

    int getmax(TreeNode* root){
        while(root -> right != NULL){
            root = root -> right;
        }
        return root -> val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        // Find the key in the bst
        if(root -> val == key){
            // Case : 1 with no child.
            if(root -> left == NULL && root -> right == NULL){
                delete root;
                return NULL;
            }
            // Case : 2 left child is not null and right is null
            else if(root -> left != NULL && root -> right == NULL){
                TreeNode* leftchild = root -> left;
                root -> left = NULL;
                delete root;
                return leftchild;
            }
            // Case : 3 left is null and right is not null
            else if(root -> left == NULL && root -> right != NULL){
                TreeNode* rightchild = root -> right;
                root -> right = NULL;
                delete root;
                return rightchild;
            }
            else{
                int maxleft = getmax(root -> left);
                root -> val = maxleft;
                root -> left = deleteNode(root -> left, maxleft);
                return root;
            }
            return NULL;
        }
        // now search on left or right
        else{
            if(key > root -> val){
                root -> right = deleteNode(root -> right, key);
            }
            else{
                root -> left = deleteNode(root -> left, key);
            }
        }
        return root;
    }
};
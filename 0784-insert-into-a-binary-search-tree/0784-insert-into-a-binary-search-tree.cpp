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
    void solve(TreeNode*& root, int& val){

        // if current node val is greater then val then go left.
        if(root -> val > val){
            if(root -> left == NULL){
                TreeNode* newNode = new TreeNode(val);
                root -> left = newNode;
                return;
            }
            solve(root -> left, val);
        }
        // if current node val is smaller then val then go right.
        else{
            if(root -> right == NULL){
                TreeNode* newNode = new TreeNode(val);
                root -> right = newNode;
                return;
            }
            solve(root -> right, val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(root == NULL){
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        solve(root, val);
        return root;
        
    }
};
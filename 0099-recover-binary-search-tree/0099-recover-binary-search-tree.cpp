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
    void solve(TreeNode*& root, vector<int>& inorder, int& i){
        if(root == NULL){
            return;
        }
        solve(root -> left, inorder, i);
        if(inorder[i] != root -> val){
            root -> val = inorder[i];
        }
        i++;
        solve(root -> right, inorder, i);
    }
    void findInorder(TreeNode*& root, vector<int>&inorder){
        if(root == NULL){
            return;
        }
        findInorder(root -> left, inorder);
        inorder.push_back(root -> val);
        findInorder(root -> right, inorder);
    }
    void recoverTree(TreeNode* root) {

        vector<int>inorder;
        findInorder(root, inorder);
        sort(inorder.begin(), inorder.end());
        int i = 0;
        solve(root, inorder, i);
    }
};
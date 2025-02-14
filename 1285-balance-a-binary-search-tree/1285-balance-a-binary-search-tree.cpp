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
    void findInorder(TreeNode* root, vector<int>&inorder){
        if(root == NULL){
            return;
        }
        findInorder(root -> left, inorder);
        inorder.push_back(root -> val);
        findInorder(root -> right, inorder);
    }
    TreeNode* constructBst(vector<int>&inorder, int s, int e){
        if(s > e){
            return NULL;
        }
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root -> left = constructBst(inorder, s, mid - 1);
        root -> right = constructBst(inorder, mid + 1, e);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {

        vector<int>inorder;
        findInorder(root, inorder);
        int s = 0, e = inorder.size() - 1;
        int i = 0;
        TreeNode* rootnode = constructBst(inorder, s, e);
        return rootnode;
    }
};
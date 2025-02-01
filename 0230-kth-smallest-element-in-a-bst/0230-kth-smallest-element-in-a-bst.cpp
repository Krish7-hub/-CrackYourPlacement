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
    void findinorder(TreeNode*& root, vector<int>&inorder){
        if(root == NULL){
            return;
        }
        findinorder(root -> left, inorder);
        inorder.push_back(root -> val);
        findinorder(root -> right, inorder);
    }
    int kthSmallest(TreeNode* root, int k) {

        vector<int>inorder;
        findinorder(root, inorder);
        int ans = inorder[k - 1];
        return ans;
        
    }
};
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
    TreeNode* solve(vector<int>&preorder, int maxi, int& i){
        if(i >= preorder.size()){
            return NULL;
        }
        if(preorder[i] > maxi){
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[i++]);
        node -> left = solve(preorder,node -> val, i);
        node -> right = solve(preorder, maxi, i);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int maxi = INT_MAX;
        int i = 0;
        TreeNode* root = solve(preorder, maxi, i);
        return root;   
    }
};
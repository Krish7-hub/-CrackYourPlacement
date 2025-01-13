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
    void storeIndex(unordered_map<int, int>&mpp, vector<int>&inorder){
        for(int i = 0; i < inorder.size(); i++){
            int index = i;
            int element = inorder[i];
            mpp[element] = index;
        }
    }
    TreeNode* solve(unordered_map<int, int>&mpp, vector<int>&inorder, vector<int>&postorder, int& postorderIndex, int inorderStartIndex, 
    int inorderEndIndex, int &len){

        if(postorderIndex < 0){
            return NULL;
        }
        if(inorderStartIndex > inorderEndIndex){
            return NULL;
        }

        int element = postorder[postorderIndex];
        postorderIndex--;
        TreeNode* root = new TreeNode(element);

        int index = mpp[element];

        root -> right = solve(mpp, inorder, postorder, postorderIndex, index + 1, inorderEndIndex, len);
        root -> left = solve(mpp, inorder, postorder, postorderIndex, inorderStartIndex, index - 1, len);

        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        int inorderStartIndex = 0;
        int inorderEndIndex = inorder.size() - 1;
        int postorderIndex = postorder.size() - 1;
        unordered_map<int, int>mpp;
        storeIndex(mpp, inorder);
        TreeNode* root = solve(mpp, inorder, postorder, postorderIndex, inorderStartIndex, inorderEndIndex, len);
        return root;
    }
};
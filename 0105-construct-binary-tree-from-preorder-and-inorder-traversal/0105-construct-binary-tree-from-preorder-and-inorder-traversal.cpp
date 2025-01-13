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
    // int getIndex(vector<int>inorder, int rootElement){
    //     for(int i = 0; i < inorder.size(); i++){
    //         if(inorder[i] == rootElement){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    
    void storeIndex(unordered_map<int, int>&mpp, vector<int>&inorder){
        for(int i = 0; i < inorder.size(); i++){
            int index = i;
            int element = inorder[i];
            mpp[element] = index;
        }
    }

    TreeNode* solve(unordered_map<int, int>&mpp, vector<int>& preorder, vector<int>& inorder, int& preorderIndex, int inorderStartIndex,
     int inorderEndIndex, int& len){

        // Base Condition
        if(preorderIndex >= len){
            return NULL;
        }
        if(inorderStartIndex > inorderEndIndex){
            return NULL;
        }

        // Step 1 -> Create the node or root of tree
        int rootElement = preorder[preorderIndex];
        preorderIndex++;
        TreeNode* root = new TreeNode(rootElement);

        int index = mpp[rootElement];

        // Call for left Subtree 
        root -> left = solve(mpp, preorder, inorder, preorderIndex, inorderStartIndex, index - 1, len);

        // Call for right Subtree
        root -> right = solve(mpp, preorder, inorder, preorderIndex, index + 1, inorderEndIndex, len);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int len = preorder.size();
        int inorderStartIndex = 0;
        int inorderEndIndex = inorder.size() - 1;
        int preorderIndex = 0;
        unordered_map<int, int>mpp;
        storeIndex(mpp, inorder);
        TreeNode* root = solve(mpp, preorder, inorder, preorderIndex, inorderStartIndex, inorderEndIndex, len); 
        return root;
    }
};
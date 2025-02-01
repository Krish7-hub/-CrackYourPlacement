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

    void findinorder(TreeNode* root, vector<int>&inorder){
        if(root == NULL)
        return;
        findinorder(root -> left, inorder);
        inorder.push_back(root -> val);
        findinorder(root -> right, inorder);
    }

    bool findTarget(TreeNode* root, int k) {

        vector<int>inorder;
        findinorder(root, inorder);
        int left = 0;
        int right = inorder.size() - 1;
        bool ans = false;
        
        while(left < right){
            int val = inorder[left] + inorder[right];
            if(val == k){
                ans = true;
                break;
            }
            else if(val > k){
                right--;
            }
            else{
                left++;
            }
        }
        return ans;
        
    }
};
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
    void findSum(TreeNode* root, int& low, int& high, int& rangeSum){
        if(root == NULL){
            return;
        }
        if(root -> val >= low && root -> val <= high){
            rangeSum += root -> val;
            findSum(root -> left, low, high, rangeSum);
            findSum(root -> right, low, high, rangeSum);
        }
        else if(root -> val < low){
            findSum(root -> right, low, high, rangeSum);
        }
        else if(root -> val > high){
            findSum(root -> left, low, high, rangeSum);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {

        int rangeSum = 0;
        findSum(root, low, high, rangeSum);
        return rangeSum;
        
    }
};
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
    string solve(TreeNode* root, vector<TreeNode*>&ans, map<string, int>&mpp){
        if(root == NULL){
            return "N";
        }
        string curr = to_string(root -> val);
        string left = solve(root->left, ans, mpp);
        string right = solve(root->right, ans, mpp);
        string finalstring = curr + ',' + left + ',' + right;
        if(mpp.find(finalstring) != mpp.end()){
            if(mpp[finalstring] == 1){
                ans.push_back(root);
            }
            mpp[finalstring]++;
        }
        else{
            mpp[finalstring] = 1;
        }
        return finalstring;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        vector<TreeNode*>ans;
        map<string, int>mpp;
        solve(root, ans, mpp);
        return ans;
        
    }
};
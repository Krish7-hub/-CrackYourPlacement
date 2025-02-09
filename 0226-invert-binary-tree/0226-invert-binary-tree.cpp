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
    TreeNode* invertTree(TreeNode* root) {

        if(root == NULL) return NULL;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front -> left != NULL) q.push(front -> left);
            if(front -> right != NULL) q.push(front -> right);
            TreeNode* temp = front -> left;
            front -> left = front -> right;
            front -> right = temp;
        }
        return root;

        
    }
};
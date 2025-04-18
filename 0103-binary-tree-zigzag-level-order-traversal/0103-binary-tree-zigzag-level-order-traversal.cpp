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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>>ans;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        bool toggle = true;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            vector<int>temp(len);
            for(int i = 0; i < len; i++){
                TreeNode* front = q.front();
                q.pop();
                int index = toggle ? i : len - i - 1;
                temp[index] = front -> val;
                if(front -> left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            toggle = !toggle;
            ans.push_back(temp);
        }
        return ans;
    }
};
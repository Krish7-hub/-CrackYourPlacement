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
        bool bulb = false;
        q.push(root);

        while(!q.empty()){

            vector<int>temp;
            int len = q.size();

            for(int i = 0; i < len; i++){

                TreeNode* front = q.front();
                q.pop();

                if(front -> left != NULL){
                    q.push(front->left);
                }
                if(front -> right != NULL){
                    q.push(front->right);
                }
                temp.push_back(front -> val);
            } 
            if(!bulb){
                ans.push_back(temp);
                bulb = true;
            }
            else{
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                bulb = false;
            }
        }
        return ans;
        
    }
};
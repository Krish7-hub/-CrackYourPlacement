/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int getlength(ListNode*& head){
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp -> next;
        }
        return cnt;
    }
    TreeNode* solve(ListNode*& head, int n){
        if(head == NULL || n <= 0){
            return NULL;
        }
        TreeNode* leftSubTree = solve(head, n/2);
        TreeNode* root = new TreeNode(head -> val);
        root -> left = leftSubTree;
        head = head -> next;
        TreeNode* rightSubTree = solve(head, n - n/2 - 1);
        root -> right = rightSubTree;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {

        int n = getlength(head);
        TreeNode* root = solve(head, n);
        return root;
        
    }
};
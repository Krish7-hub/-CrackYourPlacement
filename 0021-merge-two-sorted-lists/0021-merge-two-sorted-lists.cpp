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
class Solution {
public:
    void solve(ListNode* list1, ListNode* list2, ListNode* tempnode){
        if(list1 -> val <= list2 ->val){
            ListNode* newnode = new ListNode(list1 -> val);
            tempnode->next = newnode;
            tempnode = tempnode->next;
            list1 = list1->next;
        }
        else{
            ListNode* newnode = new ListNode(list2 -> val);
            tempnode->next = newnode;
            tempnode = tempnode->next;
            list2 = list2->next;
        }
        if(list1 == NULL){
            tempnode->next = list2;
            return;
        }
        if(list2 == NULL){
            tempnode->next = list1;
            return;
        }
        solve(list1, list2, tempnode);
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL) return NULL;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* tempnode = new ListNode(1);
        ListNode* temp = tempnode;
        solve(list1, list2, tempnode);
        return temp->next;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *prev = head,*result = head;
        head = head->next;
        while(head){
            if(head->val == prev->val) prev->next = head->next;
            else prev = head;
            head = head->next;
        }
        return result;
    }
};
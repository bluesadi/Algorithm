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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *headnext = head->next;
        ListNode *result = reverseList(head->next);
        headnext->next = head;
        head->next = NULL;
        return result;
    }
};
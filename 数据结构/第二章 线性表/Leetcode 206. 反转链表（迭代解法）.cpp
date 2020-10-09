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
        /*
        没有头结点，给他手动加一个头结点上去
        */
        ListNode *L = new ListNode;
        while(head){
            ListNode *next = head->next;
            head->next = L->next;
            L->next = head;
            head = next;
        }
        return L->next;
    }
};
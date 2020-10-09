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
    int len(ListNode *L){
        int retn = 0;
        while(L){
            retn++;
            L = L->next;
        }
        return retn;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = len(headA),lenB = len(headB);
        if(lenA > lenB){
            for(int i = 0;i < lenA - lenB;i ++){
                headA = headA->next;
            }
        }else if(lenB > lenA){
            for(int i = 0;i < lenB - lenA;i ++){
                headB = headB->next;
            }
        }
        while(headA){
            if(headA == headB) return headA;
            headA = headA->next,headB = headB->next;
        }
        return NULL;
    }
};
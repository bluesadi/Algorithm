/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stack>
using namespace std;

class Solution {
public:
    int len(ListNode* head){
        int result = 0;
        while(head) head = head->next,result++;
        return result;
    }

    bool isPalindrome(ListNode* head) {
        stack<int> S;
        int n = len(head),i = 0;
        for(int i = 0;i < n;i ++){
            if((n & 1) && i == n / 2){
                head = head->next;
                continue;
            }
            if(!S.empty() && S.top() == head->val) S.pop();
            else S.push(head->val);
            head = head->next;
        }
        return S.empty();
    }
};
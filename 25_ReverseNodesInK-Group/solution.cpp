#include "../IOLib.hpp"

/***
Time: O(n)
Space: O(1)
***/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        ListNode* preheader = new ListNode(-1);
        preheader->next = head;
        ListNode* cur = preheader;
        int n = 0;
        while(cur = cur->next)
            n++;
        ListNode* pre = preheader, *next;
        cur = preheader;
        while(n >= k){
            cur = pre->next;
            next = cur->next;
            for(int i = 1; i < k; i++){
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = cur->next;
            }
            pre = cur;
            n -= k;
        }
        return preheader->next;
    }
};

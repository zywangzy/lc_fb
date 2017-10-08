#include "../IOLib.hpp"

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0), *last = head;
        while(l1 || l2){
            if(l1 && l2){
                if(l1->val <= l2->val){
                    last->next = l1;
                    l1 = l1->next;
                }
                else{
                    last->next = l2;
                    l2 = l2->next;
                }
                last = last->next;
            }
            else if(l1){
                last->next = l1;
                break;
            }
            else{//l2
                last->next = l2;
                break;
            }
        }
        return head->next;
    }
};

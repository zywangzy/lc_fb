#include "../IOLib.hpp"

/**
Used priority queue to accelarate the process of finding next
node with smallest value to put in the next position in linked
list.
Time: O(Nlog(K))
Space: O(K)
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class mycmp{
public:
    bool operator()(ListNode*& a, ListNode*& b) const{
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(0), *last = head;
        priority_queue<ListNode*, vector<ListNode*>, mycmp> pq;
        for(int i = 0; i < lists.size(); i++)
            if(lists[i] != NULL) pq.push(lists[i]);
        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            last->next = temp;
            if(temp->next) pq.push(temp->next);
            last = last->next;
        }
        return head->next;
    }
};

#include "../IOLib.hpp"

/**
Recursive way.
1st round: count.
2nd round: put the values into tree.
Time: O(n)
Space: O(log(n))

Another way:
Each time call the original function.
Use fast & slow pointer to find mid-point, break the link
between first and second half. Then call the function on
left and right half seperately.
Time: O(nlog(n))
Space: O(1)
**/

/*Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    ListNode* ptr;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        int count = 0;
        ptr = head;
        while(head){
            count++; head = head->next;
        }
        return build(count);
    }
    TreeNode* build(int n){
        if(n == 0 || !ptr) return NULL;
        TreeNode* res = new TreeNode(0);
        res->left = build(n/2);
        res->val = ptr->val;
        ptr = ptr->next;
        res->right = build(n - n/2 - 1);
        return res;
    }
};

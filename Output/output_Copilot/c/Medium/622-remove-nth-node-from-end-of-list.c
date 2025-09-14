/**https://leetcode.com/problems/remove-nth-node-from-end-of-list/ */
//Given the head of a linked list, remove the nth node from the end of the list and return its head.
// 
//Example 1:
//Input: head = [1,2,3,4,5], n = 2
//Output: [1,2,3,5]
//Example 2:
//Input: head = [1], n = 1
//Output: []
//Example 3:
//Input: head = [1,2], n = 1
//Output: [1]
// 
//Constraints:
//	The number of nodes in the list is sz.
//	1 <= sz <= 30
//	0 <= Node.val <= 100
//	1 <= n <= sz
// 
//Follow up: Could you do this in one pass?
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p = head, *q = head;
    while (n--) {
        q = q->next;
    }
    if (q == NULL) {
        return head->next;
    }
    while (q->next) {
        p = p->next;
        q = q->next;
    }
    p->next = p->next->next;
    return head;    
}
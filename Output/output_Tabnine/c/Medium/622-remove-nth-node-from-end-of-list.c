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
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* slow = dummy;
    struct ListNode* fast = dummy;
    
    for (int i = 0; i < n + 1; i++) {
        fast = fast->next;
    }
    
    while (fast!= NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    
    struct ListNode* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);
    
    return dummy->next;
    
}
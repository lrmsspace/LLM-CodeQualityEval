/**https://leetcode.com/problems/remove-linked-list-elements/ */
//Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
// 
//Example 1:
//Input: head = [1,2,6,3,4,5,6], val = 6
//Output: [1,2,3,4,5]
//Example 2:
//Input: head = [], val = 1
//Output: []
//Example 3:
//Input: head = [7,7,7,7], val = 7
//Output: []
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 104].
//	1 <= Node.val <= 50
//	0 <= val <= 50
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (!head) return NULL;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* curr = head;
    while (curr) {
        if (curr->val == val) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy->next;
}
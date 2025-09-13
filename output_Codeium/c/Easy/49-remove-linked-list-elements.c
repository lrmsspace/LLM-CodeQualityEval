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
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *cur = dummy;
    while (cur->next != NULL) {
        if (cur->next->val == val) {
            struct ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
        } else {
            cur = cur->next;
        }
    }
    struct ListNode *ret = dummy->next;
    free(dummy);
    return ret;
}
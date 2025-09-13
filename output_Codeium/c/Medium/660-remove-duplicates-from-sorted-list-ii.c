/**https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/ */
//Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
// 
//Example 1:
//Input: head = [1,2,3,3,4,4,5]
//Output: [1,2,5]
//Example 2:
//Input: head = [1,1,1,2,3]
//Output: [2,3]
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 300].
//	-100 <= Node.val <= 100
//	The list is guaranteed to be sorted in ascending order.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) return NULL;

    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *prev = dummy;
    struct ListNode *curr = head;

    while (curr) {
        while (curr->next && curr->val == curr->next->val) {
            curr = curr->next;
        }

        if (prev->next == curr) {
            prev = prev->next;
        } else {
            prev->next = curr->next;
        }

        curr = curr->next;
    }

    return dummy->next;
    
}
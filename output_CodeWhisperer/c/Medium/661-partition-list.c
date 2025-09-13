/**https://leetcode.com/problems/partition-list/ */
//Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//You should preserve the original relative order of the nodes in each of the two partitions.
// 
//Example 1:
//Input: head = [1,4,3,2,5,2], x = 3
//Output: [1,2,2,4,3,5]
//Example 2:
//Input: head = [2,1], x = 2
//Output: [1,2]
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 200].
//	-100 <= Node.val <= 100
//	-200 <= x <= 200
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* less = NULL;
    struct ListNode* greater = NULL;
    struct ListNode* lessHead = NULL;
    struct ListNode* greaterHead = NULL;
    struct ListNode* current = head;
    while (current != NULL) {
        if (current->val < x) {
            if (less == NULL) {
                less = current;
                lessHead = less;
            } else {
                less->next = current;
                less = less->next;
            }
        } else {
            if (greater == NULL) {
                greater = current;
                greaterHead = greater;
            } else {
                greater->next = current;
                greater = greater->next;
            }
        }
        current = current->next;
    }
    if (less != NULL) {
        less->next = greaterHead;
    }
    if (greater != NULL) {
        greater->next = NULL;
    }
    return lessHead != NULL ? lessHead : greaterHead;
}
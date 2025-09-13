/**https://leetcode.com/problems/rotate-list/ */
//Given the head of a linked list, rotate the list to the right by k places.
// 
//Example 1:
//Input: head = [1,2,3,4,5], k = 2
//Output: [4,5,1,2,3]
//Example 2:
//Input: head = [0,1,2], k = 4
//Output: [2,0,1]
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 500].
//	-100 <= Node.val <= 100
//	0 <= k <= 2 * 109
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || k == 0) return head;

    // Calculate the length of the list
    struct ListNode *current = head;
    int length = 1;
    while (current->next) {
        current = current->next;
        length++;
    }

    // Make the list circular
    current->next = head;

    // Find the new head and tail
    k = k % length; // In case k is greater than length
    int stepsToNewHead = length - k;
    struct ListNode *newTail = head;
    for (int i = 0; i < stepsToNewHead - 1; i++) {
        newTail = newTail->next;
    }
    struct ListNode *newHead = newTail->next;

    // Break the circular list
    newTail->next = NULL;

    return newHead;
}   
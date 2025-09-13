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
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* temp = head;
    int count = 1;
    while (temp->next != NULL) {
        count++;
        temp = temp->next;
    }
    k = k % count;
    if (k == 0) {
        return head;
    }
    temp->next = head;
    for (int i = 0; i < count - k; i++) {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}
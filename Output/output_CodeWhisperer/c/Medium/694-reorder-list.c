/**https://leetcode.com/problems/reorder-list/ */
//You are given the head of a singly linked-list. The list can be represented as:
//L0 → L1 → … → Ln - 1 → Ln
//Reorder the list to be on the following form:
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//You may not modify the values in the list's nodes. Only nodes themselves may be changed.
// 
//Example 1:
//Input: head = [1,2,3,4]
//Output: [1,4,2,3]
//Example 2:
//Input: head = [1,2,3,4,5]
//Output: [1,5,2,4,3]
// 
//Constraints:
//	The number of nodes in the list is in the range [1, 5 * 104].
//	1 <= Node.val <= 1000
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* second = slow->next;
    slow->next = NULL;
    struct ListNode* pre = NULL;
    while (second != NULL) {
        struct ListNode* temp = second->next;
        second->next = pre;
        pre = second;
        second = temp;
    }
    second = pre;
    struct ListNode* first = head;
    while (second != NULL) {
        struct ListNode* temp1 = first->next;
        struct ListNode* temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }   
}
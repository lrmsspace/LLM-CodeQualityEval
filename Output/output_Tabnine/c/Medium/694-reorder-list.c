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
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return;
    }
    
    // Find the middle node
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse the second half of the list
    struct ListNode* prev = NULL;
    struct ListNode* curr = slow->next;
    slow->next = NULL;
    while (curr) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    
    // Merge the two halves
    struct ListNode* first = head;
    struct ListNode* second = prev;
    while (first && second) {
        struct ListNode* temp = first->next;
        first->next = second;
        first = temp;
        
        temp = second->next;
        second->next = first;
        second = temp;
    }
    
    // Update the head to the new reordered list
    head = head->next->next;
    
    return;
    
}
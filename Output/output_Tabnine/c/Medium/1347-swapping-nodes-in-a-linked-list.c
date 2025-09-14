/**https://leetcode.com/problems/swapping-nodes-in-a-linked-list/ */
//You are given the head of a linked list, and an integer k.
//Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
// 
//Example 1:
//Input: head = [1,2,3,4,5], k = 2
//Output: [1,4,3,2,5]
//Example 2:
//Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
//Output: [7,9,6,6,8,7,3,0,9,5]
// 
//Constraints:
//	The number of nodes in the list is n.
//	1 <= k <= n <= 105
//	0 <= Node.val <= 100
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k) {
    // Find the kth node from the end
    struct ListNode* end = head;
    for (int i = 1; i < k; i++) {
        if (end == NULL) return head;
        end = end->next;
    }
    
    // Find the (k-1)th node from the beginning
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    for (int i = 1; end!= NULL; i++) {
        prev = curr;
        curr = curr->next;
        end = end->next;
    }
    
    // Swap the values
    if (prev!= NULL) {
        prev->next = curr;
    }
    
    struct ListNode* temp = curr->next;
    curr->next = head;
    head = temp;
    
    return head;
    
}
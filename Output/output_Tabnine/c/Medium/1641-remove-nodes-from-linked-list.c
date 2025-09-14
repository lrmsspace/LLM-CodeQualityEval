/**https://leetcode.com/problems/remove-nodes-from-linked-list/ */
//You are given the head of a linked list.
//Remove every node which has a node with a greater value anywhere to the right side of it.
//Return the head of the modified linked list.
// 
//Example 1:
//Input: head = [5,2,13,3,8]
//Output: [13,8]
//Explanation: The nodes that should be removed are 5, 2 and 3.
//- Node 13 is to the right of node 5.
//- Node 13 is to the right of node 2.
//- Node 8 is to the right of node 3.
//Example 2:
//Input: head = [1,1,1,1]
//Output: [1,1,1,1]
//Explanation: Every node has value 1, so no nodes are removed.
// 
//Constraints:
//	The number of the nodes in the given list is in the range [1, 105].
//	1 <= Node.val <= 105
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNodes(struct ListNode* head) {
    // Create a dummy node to handle edge cases
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    dummy->next = head;
    
    // Initialize two pointers: prev and curr
    struct ListNode* prev = dummy;
    struct ListNode* curr = head;
    
    // Iterate through the linked list
    while (curr!= NULL) {
        // If the current node has a node with a greater value to the right
        while (curr->next!= NULL && curr->next->val >= curr->val) {
            curr = curr->next;
        }
        
        // If the current node is not the last node and it does not have a greater value to the right
        if (curr->next!= NULL) {
            // Remove the current node from the linked list
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            // Move the prev pointer to the current node
            prev = prev->next;
            curr = curr->next;
        }
    }
    
    // Return the modified linked list
    return dummy->next;
    
}
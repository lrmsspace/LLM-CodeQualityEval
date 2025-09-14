/**https://leetcode.com/problems/split-linked-list-in-parts/ */
//Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
//The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
//The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
//Return an array of the k parts.
// 
//Example 1:
//Input: head = [1,2,3], k = 5
//Output: [[1],[2],[3],[],[]]
//Explanation:
//The first element output[0] has output[0].val = 1, output[0].next = null.
//The last element output[4] is null, but its string representation as a ListNode is [].
//Example 2:
//Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
//Output: [[1,2,3,4],[5,6,7],[8,9,10]]
//Explanation:
//The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 1000].
//	0 <= Node.val <= 1000
//	1 <= k <= 50
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    // Count the total number of nodes
    struct ListNode* curr = head;
    int count = 0;
    while (curr) {
        count++;
        curr = curr->next;
    }
    
    // Calculate the size of each part and the number of extra nodes
    int size = count / k;
    int extra = count % k;
    
    // Allocate the result array and initialize pointers
    struct ListNode** result = malloc(k * sizeof(struct ListNode*));
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    
    // Split the list into k parts
    for (int i = 0; i < k; i++) {
        result[i] = prev->next;
        
        // Move the pointers to the next part
        for (int j = 0; j < size - (i < extra? 1 : 0); j++) {
            prev = prev->next;
        }
        
        // Break the connection to the next part
        prev->next = curr? curr->next : NULL;
    }
    
    // Free the dummy node
    free(dummy);
    
    // Update the return size
    *returnSize = k;
    
    return result;
    
}
/**https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/ */
//Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
//After doing so, return the head of the final linked list.  You may return any such answer.
// 
//(Note that in the examples below, all sequences are serializations of ListNode objects.)
//Example 1:
//Input: head = [1,2,-3,3,1]
//Output: [3,1]
//Note: The answer [1,2,1] would also be accepted.
//Example 2:
//Input: head = [1,2,3,-3,4]
//Output: [1,2,4]
//Example 3:
//Input: head = [1,2,3,-3,-2]
//Output: [1]
// 
//Constraints:
//	The given linked list will contain between 1 and 1000 nodes.
//	Each node in the linked list has -1000 <= node.val <= 1000.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    int sum = 0;
    
    while (head) {
        sum += head->val;
        while (prev->next && sum!= 0) {
            prev = prev->next;
            sum -= prev->next->val;
        }
        if (sum == 0) {
            prev->next = head->next;
        } else {
            prev = head;
        }
        head = head->next;
    }
    
    return dummy->next;
    
}
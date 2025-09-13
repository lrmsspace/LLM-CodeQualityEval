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
    struct ListNode* dummy1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* dummy2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy1->next = NULL;
    dummy2->next = NULL;
    struct ListNode* prev1 = dummy1;
    struct ListNode* prev2 = dummy2;
    
    while (head!= NULL) {
        if (head->val < x) {
            prev1->next = head;
            prev1 = prev1->next;
        } else {
            prev2->next = head;
            prev2 = prev2->next;
        }
        head = head->next;
    }
    
    prev1->next = dummy2->next;
    prev2->next = NULL;
    
    return dummy1->next;
    
}
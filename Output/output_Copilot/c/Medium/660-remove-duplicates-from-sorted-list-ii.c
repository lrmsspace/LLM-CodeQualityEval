/**https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/ */
//Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
// 
//Example 1:
//Input: head = [1,2,3,3,4,4,5]
//Output: [1,2,5]
//Example 2:
//Input: head = [1,1,1,2,3]
//Output: [2,3]
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 300].
//	-100 <= Node.val <= 100
//	The list is guaranteed to be sorted in ascending order.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *pre = dummy;
    struct ListNode *cur = head;
    while(cur != NULL) {
        while(cur->next != NULL && cur->val == cur->next->val) {
            cur = cur->next;
        }
        if(pre->next == cur) {
            pre = pre->next;
        } else {
            pre->next = cur->next;
        }
        cur = cur->next;
    }
    return dummy->next;    
}
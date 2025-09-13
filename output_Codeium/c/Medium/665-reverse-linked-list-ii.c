/**https://leetcode.com/problems/reverse-linked-list-ii/ */
//Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
// 
//Example 1:
//Input: head = [1,2,3,4,5], left = 2, right = 4
//Output: [1,4,3,2,5]
//Example 2:
//Input: head = [5], left = 1, right = 1
//Output: [5]
// 
//Constraints:
//	The number of nodes in the list is n.
//	1 <= n <= 500
//	-500 <= Node.val <= 500
//	1 <= left <= right <= n
// 
//Follow up: Could you do it in one pass?
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *pre = dummy;
    int count = 1;
    while (count < left) {
        pre = pre->next;
        count++;
    }
    struct ListNode *cur = pre->next;
    struct ListNode *next;
    int i = 0;
    while (i < right - left) {
        next = cur->next;
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
        i++;
    }
    return dummy->next;
}

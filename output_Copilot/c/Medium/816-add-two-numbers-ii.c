/**https://leetcode.com/problems/add-two-numbers-ii/ */
//You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// 
//Example 1:
//Input: l1 = [7,2,4,3], l2 = [5,6,4]
//Output: [7,8,0,7]
//Example 2:
//Input: l1 = [2,4,3], l2 = [5,6,4]
//Output: [8,0,7]
//Example 3:
//Input: l1 = [0], l2 = [0]
//Output: [0]
// 
//Constraints:
//	The number of nodes in each linked list is in the range [1, 100].
//	0 <= Node.val <= 9
//	It is guaranteed that the list represents a number that does not have leading zeros.
// 
//Follow up: Could you solve it without reversing the input lists?
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1, *p2 = l2;
    int len1 = 0, len2 = 0;
    while (p1) {
        len1++;
        p1 = p1->next;
    }
    while (p2) {
        len2++;
        p2 = p2->next;
    }
    if (len1 < len2) {
        struct ListNode *temp = l1;
        l1 = l2;
        l2 = temp;
        int len = len1;
        len1 = len2;
        len2 = len;
    }
    struct ListNode *head = l1, *prev = NULL;
    int carry = 0;
    while (l1) {
        int sum = l1->val + (len2 > 0 ? l2->val : 0) + carry;
        l1->val = sum % 10;
        carry = sum / 10;
        len1--;
        len2--;
        prev = l1;
        l1 = l1->next;
        if (len2 > 0) {
            l2 = l2->next;
        }
    }
    if (carry) {
        struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = carry;
        new->next = NULL;
        prev->next = new;
    }
    return head;    
}
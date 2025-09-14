/**https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/ */
//You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
//Return the head of the linked list after doubling it.
// 
//Example 1:
//Input: head = [1,8,9]
//Output: [3,7,8]
//Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
//Example 2:
//Input: head = [9,9,9]
//Output: [1,9,9,8]
//Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 
// 
//Constraints:
//	The number of nodes in the list is in the range [1, 104]
//	0 <= Node.val <= 9
//	The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* doubleIt(struct ListNode* head){
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* cur = dummy;
    int carry = 0;
    while(cur){
        cur->next->val *= 2;
        carry = cur->next->val / 10;
        cur->next->val %= 10;
        cur = cur->next;
    }
    if(carry){
        cur->next = malloc(sizeof(struct ListNode));
    }
    while(carry){
        cur->next->val = carry % 10;
        carry /= 10;
        cur = cur->next;
    }
    return dummy->next;
}
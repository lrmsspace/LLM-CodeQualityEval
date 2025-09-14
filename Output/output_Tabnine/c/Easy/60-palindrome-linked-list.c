/**https://leetcode.com/problems/palindrome-linked-list/ */
//Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
// 
//Example 1:
//Input: head = [1,2,2,1]
//Output: true
//Example 2:
//Input: head = [1,2]
//Output: false
// 
//Constraints:
//	The number of nodes in the list is in the range [1, 105].
//	0 <= Node.val <= 9
// 
//Follow up: Could you do it in O(n) time and O(1) space?
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    struct ListNode* reverseSecondHalf = reverseLinkedList(slow);
    
    struct ListNode* curr = head;
    struct ListNode* nextNode = NULL;
    
    while (curr && reverseSecondHalf) {
        if (curr->val!= reverseSecondHalf->val) {
            return false;
        }
        
        nextNode = curr->next;
        curr->next = reverseSecondHalf->next;
        reverseSecondHalf->next = curr;
        
        curr = nextNode;
        reverseSecondHalf = reverseSecondHalf->next;
    }
    
    return true;
}
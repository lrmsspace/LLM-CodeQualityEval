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
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    let slow = head, fast = head, prev = null, temp = null;
    while (fast && fast.next) {
        fast = fast.next.next;
        temp = slow.next;
        slow.next = prev;
        prev = slow;
        slow = temp;
    }
    if (fast) slow = slow.next; // for odd length
    while (prev && slow) {
        if (prev.val !== slow.val) return false;
        prev = prev.next;
        slow = slow.next;
    }
    return true;    
};
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
    let slow = head;
    let fast = head;
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    let prev = null;
    while (slow) {
        let next = slow.next;
        slow.next = prev;
        prev = slow;
        slow = next;
    }
    while (prev) {
        if (prev.val !== head.val) return false;
        prev = prev.next;
        head = head.next;
    }
    return true;
};
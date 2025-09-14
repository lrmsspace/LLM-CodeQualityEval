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
    // Base case: if the list is empty or has only one node, it's a palindrome
    if (head === null || head.next === null) {
        return true;
    }
    
    // Find the middle node of the list
    let slow = head;
    let fast = head;
    while (fast.next && fast.next.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    
    // Reverse the second half of the list
    let prev = null;
    let current = slow.next;
    while (current) {
        let next = current.next;
        current.next = prev;
        prev = current;
        current = next;
    }
    
    // Compare the first half of the list with the reversed second half
    let firstHalf = head;
    let secondHalf = prev;
    while (firstHalf && secondHalf) {
        if (firstHalf.val!== secondHalf.val) {
            return false;
        }
        firstHalf = firstHalf.next;
        secondHalf = secondHalf.next;
    }
    
    return true;
    
};
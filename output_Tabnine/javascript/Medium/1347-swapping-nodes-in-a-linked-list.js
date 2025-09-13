/**https://leetcode.com/problems/swapping-nodes-in-a-linked-list/ */
//You are given the head of a linked list, and an integer k.
//Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
// 
//Example 1:
//Input: head = [1,2,3,4,5], k = 2
//Output: [1,4,3,2,5]
//Example 2:
//Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
//Output: [7,9,6,6,8,7,3,0,9,5]
// 
//Constraints:
//	The number of nodes in the list is n.
//	1 <= k <= n <= 105
//	0 <= Node.val <= 100
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var swapNodes = function(head, k) {
    // Initialize two pointers, slow and fast, to traverse the linked list
    let slow = head;
    let fast = head;
    
    // Move the fast pointer k steps ahead
    for (let i = 0; i < k - 1; i++) {
        if (fast === null) return head; // If k is greater than the length of the list, return the original list
        fast = fast.next;
    }
    
    // Move the slow pointer until the end of the list or until the fast pointer meets the slow pointer
    while (fast.next!== null) {
        slow = slow.next;
        fast = fast.next;
    }
    
    // Swap the values of the kth node from the beginning and the kth node from the end
    let temp = slow.val;
    slow.val = fast.val;
    fast.val = temp;
    
    return head; // Return the updated head of the linked list
    
};
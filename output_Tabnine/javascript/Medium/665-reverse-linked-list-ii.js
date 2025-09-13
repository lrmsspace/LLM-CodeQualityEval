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
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} left
 * @param {number} right
 * @return {ListNode}
 */
var reverseBetween = function(head, left, right) {
    // Edge case: if left equals right, return the original head
    if (left === right) return head;
    
    let dummy = new ListNode(0);
    dummy.next = head;
    let prev = dummy;
    
    // Find the (left - 1)th node
    for (let i = 0; i < left - 1; i++) {
        prev = prev.next;
    }
    
    // Reverse the nodes from left to right
    let curr = prev.next;
    for (let i = 0; i < right - left + 1; i++) {
        let nextTemp = curr.next;
        curr.next = nextTemp.next;
        nextTemp.next = prev.next;
        prev.next = nextTemp;
    }
    
    return dummy.next;
    
};
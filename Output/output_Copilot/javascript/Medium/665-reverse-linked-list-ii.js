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
    let dummy = new ListNode(0, head);
    let prev = dummy;
    for (let i = 0; i < left - 1; i++) {
        prev = prev.next;
    }
    let curr = prev.next;
    for (let i = 0; i < right - left; i++) {
        let temp = curr.next;
        curr.next = temp.next;
        temp.next = prev.next;
        prev.next = temp;
    }
    return dummy.next;    
};
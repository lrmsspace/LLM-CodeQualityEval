/**https://leetcode.com/problems/swap-nodes-in-pairs/ */
//Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
// 
//Example 1:
//Input: head = [1,2,3,4]
//Output: [2,1,4,3]
//Explanation:
//Example 2:
//Input: head = []
//Output: []
//Example 3:
//Input: head = [1]
//Output: [1]
//Example 4:
//Input: head = [1,2,3]
//Output: [2,1,3]
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 100].
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
 * @return {ListNode}
 */
var swapPairs = function(head) {
    if (head == null || head.next == null) {
        return head;
    }
    let dummy = new ListNode(0);
    dummy.next = head;
    let curr = dummy;
    while (curr.next != null && curr.next.next != null) {
        let first = curr.next;
        let second = curr.next.next;
        first.next = second.next;
        curr.next = second;
        curr.next.next = first;
        curr = curr.next.next;
    }
    return dummy.next;
};
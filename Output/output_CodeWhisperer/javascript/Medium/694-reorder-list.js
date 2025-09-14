/**https://leetcode.com/problems/reorder-list/ */
//You are given the head of a singly linked-list. The list can be represented as:
//L0 → L1 → … → Ln - 1 → Ln
//Reorder the list to be on the following form:
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
//You may not modify the values in the list's nodes. Only nodes themselves may be changed.
// 
//Example 1:
//Input: head = [1,2,3,4]
//Output: [1,4,2,3]
//Example 2:
//Input: head = [1,2,3,4,5]
//Output: [1,5,2,4,3]
// 
//Constraints:
//	The number of nodes in the list is in the range [1, 5 * 104].
//	1 <= Node.val <= 1000
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
    if (!head || !head.next) return;
    let slow = head;
    let fast = head;
    while (fast.next && fast.next.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    let prev = null;
    let curr = slow.next;
    while (curr) {
        let next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
    }
    slow.next = null;
    let p1 = head;
    let p2 = prev;
    while (p2) {
        let next = p1.next;
        p1.next = p2;
        p2 = p2.next;
        p1.next.next = next;
        p1 = next;
    }
    return head;
};
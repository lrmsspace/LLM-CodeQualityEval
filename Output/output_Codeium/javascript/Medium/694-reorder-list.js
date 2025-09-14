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
    if (!head || !head.next || !head.next.next) return;

    let slow = head;
    let fast = head;
    let preSlow = null;
    while (fast && fast.next) {
        preSlow = slow;
        slow = slow.next;
        fast = fast.next.next;
    }

    preSlow.next = null;

    let tail = reverse(slow);
    let cur1 = head;
    let cur2 = tail;
    while (cur2) {
        let next1 = cur1.next;
        let next2 = cur2.next;
        cur1.next = cur2;
        cur2.next = next1;
        cur1 = next1;
        cur2 = next2;
    }

    function reverse(head) {
        let pre = null;
        let cur = head;
        while (cur) {
            let next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
        
};
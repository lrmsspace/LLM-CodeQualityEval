/**https://leetcode.com/problems/remove-duplicates-from-sorted-list/ */
//Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
// 
//Example 1:
//Input: head = [1,1,2]
//Output: [1,2]
//Example 2:
//Input: head = [1,1,2,3,3]
//Output: [1,2,3]
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 300].
//	-100 <= Node.val <= 100
//	The list is guaranteed to be sorted in ascending order.
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
var deleteDuplicates = function(head) {
    if (!head ||!head.next) return head;
    
    let dummy = new ListNode(0, head);
    let current = dummy;
    
    while (current.next && current.next.next) {
        if (current.next.val === current.next.next.val) {
            let val = current.next.val;
            while (current.next && current.next.val === val) {
                current.next = current.next.next;
            }
        } else {
            current = current.next;
        }
    }
    
    return dummy.next;
    
};
/**https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/ */
//Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
// 
//Example 1:
//Input: head = [1,2,3,3,4,4,5]
//Output: [1,2,5]
//Example 2:
//Input: head = [1,1,1,2,3]
//Output: [2,3]
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 300].
//	-100 <= Node.val <= 100
//	The list is guaranteed to be sorted in ascending order.
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return null;
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;
        ListNode curr = head;
        
        while (curr != null) {
            if (curr.next != null && curr.val == curr.next.val) {
                while (curr.next != null && curr.val == curr.next.val) {
                    curr = curr.next;
                }
                prev.next = curr.next; // Skip all duplicates
            } else {
                prev = prev.next; // Move to next distinct node
            }
            curr = curr.next; // Move to next node
        }
        
        return dummy.next; // Return the modified list without duplicates        
    }
}
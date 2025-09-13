/**https://leetcode.com/problems/reverse-nodes-in-k-group/ */
//Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
//k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
//You may not alter the values in the list's nodes, only nodes themselves may be changed.
// 
//Example 1:
//Input: head = [1,2,3,4,5], k = 2
//Output: [2,1,4,3,5]
//Example 2:
//Input: head = [1,2,3,4,5], k = 3
//Output: [3,2,1,4,5]
// 
//Constraints:
//	The number of nodes in the list is n.
//	1 <= k <= n <= 5000
//	0 <= Node.val <= 1000
// 
//Follow-up: Can you solve the problem in O(1) extra memory space?
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
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode pre = dummy;
        ListNode cur = head;
        int count = 0;
        while (cur != null) {
            count++;
            if (count % k == 0) {
                pre = reverse(pre, cur.next);
                cur = pre.next;
            } else {
                cur = cur.next;
            }
        }
        return dummy.next;
    }

    private ListNode reverse(ListNode pre, ListNode next) {
        ListNode last = pre.next;
        ListNode cur = last.next;
        while (cur != next) {
            last.next = cur.next;
            cur.next = pre.next;
            pre.next = cur;
            cur = last.next;
        }
        return last;
    }
}
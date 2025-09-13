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
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        if (head == null || head.next == null || k <= 1) return head;
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        ListNode slow = dummy, fast = dummy;
        
        // Find the kth node from the end
        for (int i = 0; i < k - 1; i++) {
            fast = fast.next;
        }
        
        // Find the (k - 1)th node from the beginning
        while (fast.next!= null) {
            slow = slow.next;
            fast = fast.next;
        }
        
        // Swap the values of the kth node from the beginning and the kth node from the end
        int temp = slow.next.val;
        slow.next.val = fast.next.val;
        fast.next.val = temp;
        
        return dummy.next;  // Return the new head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end.
        
    }
}
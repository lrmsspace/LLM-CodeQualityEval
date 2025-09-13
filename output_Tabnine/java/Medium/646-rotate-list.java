/**https://leetcode.com/problems/rotate-list/ */
//Given the head of a linked list, rotate the list to the right by k places.
// 
//Example 1:
//Input: head = [1,2,3,4,5], k = 2
//Output: [4,5,1,2,3]
//Example 2:
//Input: head = [0,1,2], k = 4
//Output: [2,0,1]
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 500].
//	-100 <= Node.val <= 100
//	0 <= k <= 2 * 109
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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) return head;
        
        ListNode fast = head;
        ListNode slow = head;
        
        // Move fast pointer k steps ahead
        for (int i = 0; i < k; i++) {
            if (fast == null) return head; // k is larger than the length of the list
            fast = fast.next;
        }
        
        // Move both pointers until fast pointer reaches the end of the list
        while (fast.next!= null) {
            fast = fast.next;
            slow = slow.next;
        }
        
        // Connect the last node of the list to the head
        fast.next = head;
        
        // Move the slow pointer to the next node after the rotation
        slow = slow.next;
        
        // Break the connection
        head = slow.next;
        slow.next = null;
        
        return head;
        
    }
}
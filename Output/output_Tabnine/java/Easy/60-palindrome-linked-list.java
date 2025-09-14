/**https://leetcode.com/problems/palindrome-linked-list/ */
//Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
// 
//Example 1:
//Input: head = [1,2,2,1]
//Output: true
//Example 2:
//Input: head = [1,2]
//Output: false
// 
//Constraints:
//	The number of nodes in the list is in the range [1, 105].
//	0 <= Node.val <= 9
// 
//Follow up: Could you do it in O(n) time and O(1) space?
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
    public boolean isPalindrome(ListNode head) {
        // Base case: if the list is empty or has only one node, it's a palindrome
        if (head == null || head.next == null) {
            return true;
        }
        
        // Find the middle node of the list
        ListNode slow = head, fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        // Reverse the second half of the list
        ListNode prev = null;
        ListNode curr = slow.next;
        while (curr != null) {
            ListNode nextTemp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextTemp;
        }
        
        // Compare the first half of the list with the reversed second half
        slow.next = prev;
        ListNode left = head, right = slow.next;
        while (left!= slow && right!= null) {
            if (left.val!= right.val) {
                return false;
            }
            left = left.next;
            right = right.next;
        }
        
        return true;
        
    }
}
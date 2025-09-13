/**https://leetcode.com/problems/add-two-numbers/ */
//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// 
//Example 1:
//Input: l1 = [2,4,3], l2 = [5,6,4]
//Output: [7,0,8]
//Explanation: 342 + 465 = 807.
//Example 2:
//Input: l1 = [0], l2 = [0]
//Output: [0]
//Example 3:
//Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//Output: [8,9,9,9,0,0,0,1]
// 
//Constraints:
//	The number of nodes in each linked list is in the range [1, 100].
//	0 <= Node.val <= 9
//	It is guaranteed that the list represents a number that does not have leading zeros.
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0); // Dummy node to simplify the code
        ListNode current = dummyHead; // Pointer to the current node in the result list
        int carry = 0; // Variable to store the carry value

        while (l1 != null || l2 != null || carry != 0) {
            int sum = carry; // Start with the carry value

            if (l1 != null) {
                sum += l1.val; // Add the value from l1 if it's not null
                l1 = l1.next; // Move to the next node in l1
            }

            if (l2 != null) {
                sum += l2.val; // Add the value from l2 if it's not null
                l2 = l2.next; // Move to the next node in l2
            }

            carry = sum / 10; // Calculate the new carry value
            current.next = new ListNode(sum % 10); // Create a new node with the sum's last digit
            current = current.next; // Move to the next node in the result list
        }

        return dummyHead.next; // Return the next node after the dummy head, which is the actual result list        
    }
}
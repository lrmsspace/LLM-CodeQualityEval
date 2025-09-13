/**https://leetcode.com/problems/insertion-sort-list/ */
//Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
//The steps of the insertion sort algorithm:
//	Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
//	At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
//	It repeats until no input elements remain.
//The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.
// 
//Example 1:
//Input: head = [4,2,1,3]
//Output: [1,2,3,4]
//Example 2:
//Input: head = [-1,5,3,4,0]
//Output: [-1,0,3,4,5]
// 
//Constraints:
//	The number of nodes in the list is in the range [1, 5000].
//	-5000 <= Node.val <= 5000
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
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode dummy = new ListNode(0); // Dummy node to simplify insertion logic
        ListNode curr = head; // Pointer to traverse the original list

        while (curr != null) {
            ListNode prev = dummy; // Pointer to find the correct position for curr
            // Find the position to insert curr
            while (prev.next != null && prev.next.val < curr.val) {
                prev = prev.next;
            }
            // Insert curr between prev and prev.next
            ListNode nextTemp = curr.next; // Store the next node to process
            curr.next = prev.next; // Link curr to the next node in sorted part
            prev.next = curr; // Link prev to curr
            curr = nextTemp; // Move to the next node in the original list
        }
        return dummy.next; // Return the sorted list starting from the first element after dummy        
    }
}
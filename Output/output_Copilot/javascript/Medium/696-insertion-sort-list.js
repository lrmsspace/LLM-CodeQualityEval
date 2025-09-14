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
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var insertionSortList = function(head) {
    if (!head || !head.next) return head; // If the list is empty or has only one node, return it as is.

    let dummy = new ListNode(0); // Create a dummy node to simplify insertion logic.
    let current = head; // Pointer to traverse the original list.

    while (current) {
        let prev = dummy; // Pointer to find the correct position for the current node in the sorted part.
        let next = current.next; // Store the next node to process after inserting the current node.

        // Find the correct position to insert the current node in the sorted part.
        while (prev.next && prev.next.val < current.val) {
            prev = prev.next;
        }

        // Insert the current node between prev and prev.next.
        current.next = prev.next;
        prev.next = current;

        // Move to the next node in the original list.
        current = next;
    }

    return dummy.next; // Return the sorted list, which starts after the dummy node.    
};
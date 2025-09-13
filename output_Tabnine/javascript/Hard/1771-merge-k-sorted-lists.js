/**https://leetcode.com/problems/merge-k-sorted-lists/ */
//You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//Merge all the linked-lists into one sorted linked-list and return it.
// 
//Example 1:
//Input: lists = [[1,4,5],[1,3,4],[2,6]]
//Output: [1,1,2,3,4,4,5,6]
//Explanation: The linked-lists are:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//merging them into one sorted list:
//1->1->2->3->4->4->5->6
//Example 2:
//Input: lists = []
//Output: []
//Example 3:
//Input: lists = [[]]
//Output: []
// 
//Constraints:
//	k == lists.length
//	0 <= k <= 104
//	0 <= lists[i].length <= 500
//	-104 <= lists[i][j] <= 104
//	lists[i] is sorted in ascending order.
//	The sum of lists[i].length will not exceed 104.
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function(lists) {
    // Use a min-heap to keep track of the smallest elements from the lists
    const minHeap = [];
    
    // Add the heads of the lists to the min-heap
    for (let list of lists) {
        if (list) {
            minHeap.push(list);
        }
    }
    
    // If the min-heap is empty, return null
    if (minHeap.length === 0) {
        return null;
    }
    
    // Initialize the result list with the head of the smallest element
    let dummy = new ListNode(0);
    let curr = dummy;
    
    // While there are still elements in the min-heap
    while (minHeap.length > 0) {
        // Remove the smallest element from the min-heap
        const smallest = minHeap.shift();
        
        // Add the smallest element to the result list
        curr.next = smallest;
        curr = curr.next;
        
        // If there is another element in the same list, add it back to the min-heap
        if (smallest.next) {
            minHeap.push(smallest.next);
        }
    }
    
    // Return the head of the result list
    return dummy.next;
    
};
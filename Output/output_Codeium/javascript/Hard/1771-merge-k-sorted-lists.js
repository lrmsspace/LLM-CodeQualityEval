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
    if (!lists.length) return null;
    let head = new ListNode(0);
    let curr = head;
    let heap = [];
    for (let i = 0; i < lists.length; i++) {
        if (lists[i]) {
            heap.push({
                val: lists[i].val,
                node: lists[i]
            });
        }
    }
    heap.sort((a, b) => a.val - b.val);
    while (heap.length) {
        let smallest = heap.shift();
        curr.next = smallest.node;
        curr = curr.next;
        if (smallest.node.next) {
            heap.push({
                val: smallest.node.next.val,
                node: smallest.node.next
            });
            heap.sort((a, b) => a.val - b.val);
        }
    }
    return head.next;
};
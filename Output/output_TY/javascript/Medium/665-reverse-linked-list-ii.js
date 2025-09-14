/**https://leetcode.com/problems/reverse-linked-list-ii/ */
//Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
// 
//Example 1:
//Input: head = [1,2,3,4,5], left = 2, right = 4
//Output: [1,4,3,2,5]
//Example 2:
//Input: head = [5], left = 1, right = 1
//Output: [5]
// 
//Constraints:
//	The number of nodes in the list is n.
//	1 <= n <= 500
//	-500 <= Node.val <= 500
//	1 <= left <= right <= n
// 
//Follow up: Could you do it in one pass?
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} left
 * @param {number} right
 * @return {ListNode}
 */
var reverseBetween = function(head, left, right) {
    let curr = head;
    let prev = null;
    let next = null;
    let start = null;
    let end = null;
    let count = 1;
    while(curr){
        if(count === left){
            start = prev;
            end = curr;
        }
        if(count >= left && count <= right){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }else{
            prev = curr;
            curr = curr.next;
        }
        count++;
    }
    if(start){
        start.next = prev;
    }else{
       head = prev;
    }
    end.next = curr;
    return head;
};
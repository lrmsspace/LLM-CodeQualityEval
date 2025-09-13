/**https://leetcode.com/problems/add-two-numbers-ii/ */
//You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// 
//Example 1:
//Input: l1 = [7,2,4,3], l2 = [5,6,4]
//Output: [7,8,0,7]
//Example 2:
//Input: l1 = [2,4,3], l2 = [5,6,4]
//Output: [8,0,7]
//Example 3:
//Input: l1 = [0], l2 = [0]
//Output: [0]
// 
//Constraints:
//	The number of nodes in each linked list is in the range [1, 100].
//	0 <= Node.val <= 9
//	It is guaranteed that the list represents a number that does not have leading zeros.
// 
//Follow up: Could you solve it without reversing the input lists?
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let stack1 = [];
    let stack2 = [];
    while(l1){
        stack1.push(l1.val);
        l1 = l1.next;
    }
    while(l2){
        stack2.push(l2.val);
        l2 = l2.next;
    }
    let carry = 0;
    let head = null;
    while(stack1.length || stack2.length || carry){
        let sum = carry;
        sum += stack1.length ? stack1.pop() : 0;
        sum += stack2.length ? stack2.pop() : 0;
        carry = Math.floor(sum / 10);
    }
    while(carry){
        let node = new ListNode(carry % 10);
        node.next = head;
        head = node;
        carry = Math.floor(carry / 10);
    }
    return head;
};
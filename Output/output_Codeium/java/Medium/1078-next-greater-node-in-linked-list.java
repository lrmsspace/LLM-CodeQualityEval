/**https://leetcode.com/problems/next-greater-node-in-linked-list/ */
//You are given the head of a linked list with n nodes.
//For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.
//Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.
// 
//Example 1:
//Input: head = [2,1,5]
//Output: [5,5,0]
//Example 2:
//Input: head = [2,7,4,3,5]
//Output: [7,0,5,5,0]
// 
//Constraints:
//	The number of nodes in the list is n.
//	1 <= n <= 104
//	1 <= Node.val <= 109
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
    public int[] nextLargerNodes(ListNode head) {
        List<Integer> result = new ArrayList<>();
        Stack<ListNode> stack = new Stack<>();
        while (head != null) {
            while (!stack.isEmpty() && stack.peek().val < head.val) {
                result.add(head.val);
                stack.pop();
            }
            result.add(0);
            stack.push(head);
            head = head.next;
        }
        int[] arr = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            arr[i] = result.get(i);
        }
        return arr;
    }
}
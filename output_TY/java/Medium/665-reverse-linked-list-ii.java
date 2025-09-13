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
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(head == null || head.next == null || left == right){
            return head;
        }
        ListNode temp = head;
        ListNode prev = null;
        ListNode start = null;
        ListNode end = null;
        ListNode next = null;
        int count = 1;
        while(temp != null){
            if(count == left){
                start = prev;
                end = temp;
            }
            if(count == right){
                next = temp.next;
                temp.next = null;
                break;
            }
            prev = temp;
            temp = temp.next;
            count++;
        }
        ListNode reversed= reverse(end);
        if(start == null){
            head = reversed;
        }else{
            start.next = reversed;
        }
        while(start.next != null){
            start = start.next;
        }
        start.next = next;
        return head;
    }
}
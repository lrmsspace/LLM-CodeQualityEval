/**https://leetcode.com/problems/sort-list/ */
//Given the head of a linked list, return the list after sorting it in ascending order.
// 
//Example 1:
//Input: head = [4,2,1,3]
//Output: [1,2,3,4]
//Example 2:
//Input: head = [-1,5,3,4,0]
//Output: [-1,0,3,4,5]
//Example 3:
//Input: head = []
//Output: []
// 
//Constraints:
//	The number of nodes in the list is in the range [0, 5 * 104].
//	-105 <= Node.val <= 105
// 
//Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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
    public ListNode sortList(ListNode head) {
        return sort(head, null);
    }
    
    private ListNode sort(ListNode head, ListNode tail){
        if(head == null) return head;
        if(head.next == tail){
            head.next = null;
            return head;
        }
        ListNode slow = head, fast = head;
        while(fast != tail){
            slow = slow.next;
            fast = fast.next;
            if(fast != tail) fast = fast.next;
        }
        ListNode mid = slow;
        return merge(sort(head, mid), sort(mid, tail));
    }
    
    private ListNode merge(ListNode l1, ListNode l2){
        ListNode dummyHead = new ListNode(0);
        ListNode temp = dummyHead, temp1 = l1, temp2 = l2;
        while(temp1 != null && temp2 != null){
            if(temp1.val <= temp2.val){
                temp.next = temp1;
                temp1 = temp1.next;
            }else{
                temp.next = temp2;
                temp2 = temp2.next;
            }
            temp = temp.next;
        }
        if(temp1 != null) temp.next = temp1;
        else if(temp2 != null) temp.next = temp2;
        return dummyHead.next;
    }
}
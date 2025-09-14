#https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/
#You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
#Return the head of the linked list after doubling it.
# 
#Example 1:
#Input: head = [1,8,9]
#Output: [3,7,8]
#Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
#Example 2:
#Input: head = [9,9,9]
#Output: [1,9,9,8]
#Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 
# 
#Constraints:
#	The number of nodes in the list is in the range [1, 104]
#	0 <= Node.val <= 9
#	The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def doubleIt(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if head.val == 0: return head
        while head.next: head = head.next
        while head.val < 9: head.val *= 2; head = head.next
        head.val *= 2
        head.next = ListNode(head.val / 10)
        head.val %= 10
        while head.next.val == 0: head.next = head.next.next
        return head
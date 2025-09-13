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
        def doubleItHelper(node):
            if not node:
                return 0
            
            doubled_value = node.val * 2 + doubleItHelper(node.next)
            node.val = doubled_value % 10
            return doubled_value // 10
        
        carry = doubleItHelper(head)
        if carry:
            new_head = ListNode(carry)
            new_head.next = head
            return new_head
        else:
            return head
        
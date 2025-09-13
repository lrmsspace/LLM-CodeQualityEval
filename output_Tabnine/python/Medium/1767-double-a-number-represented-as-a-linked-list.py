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
        # Initialize two pointers: slow and fast
        slow = head
        fast = head
        
        # Iterate until the end of the linked list
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        # If the original list has an odd number of nodes,
        # the slow pointer will be at the middle node
        if fast:
            slow = slow.next
        
        # Double the value of the nodes at the middle position
        while slow:
            slow.val *= 2
            
            # If the doubled value is greater than 9,
            # split it into two separate digits
            if slow.val > 9:
                slow.val = slow.val // 10 + slow.val % 10
                # Create a new node with the second digit
                new_node = ListNode(slow.val // 10)
                new_node.next = slow
                slow.next = new_node
        
        return head
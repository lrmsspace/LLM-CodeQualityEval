#https://leetcode.com/problems/swap-nodes-in-pairs/
#Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
# 
#Example 1:
#Input: head = [1,2,3,4]
#Output: [2,1,4,3]
#Explanation:
#Example 2:
#Input: head = []
#Output: []
#Example 3:
#Input: head = [1]
#Output: [1]
#Example 4:
#Input: head = [1,2,3]
#Output: [2,1,3]
# 
#Constraints:
#	The number of nodes in the list is in the range [0, 100].
#	0 <= Node.val <= 100
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        # Edge cases
        if not head or not head.next:
            return head
        
        # Create a dummy node
        dummy = ListNode(0)
        dummy.next = head
        
        # Initialize the previous node
        prev = dummy
        
        # Iterate through the list
        while prev.next and prev.next.next:
            # Swap the two nodes
            node1 = prev.next
            node2 = prev.next.next
            
            # Swap
            prev.next = node2
            node1.next = node2.next
            node2.next = node1
            
            # Move the previous node two steps forward
            prev = node1
        
        return dummy.next

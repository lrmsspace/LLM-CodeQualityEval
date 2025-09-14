#https://leetcode.com/problems/rotate-list/
#Given the head of a linked list, rotate the list to the right by k places.
# 
#Example 1:
#Input: head = [1,2,3,4,5], k = 2
#Output: [4,5,1,2,3]
#Example 2:
#Input: head = [0,1,2], k = 4
#Output: [2,0,1]
# 
#Constraints:
#	The number of nodes in the list is in the range [0, 500].
#	-100 <= Node.val <= 100
#	0 <= k <= 2 * 109
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        # Edge case: If the list is empty or k is 0, return the head
        if not head or k == 0:
            return head
        
        # Find the length of the linked list
        length = 1
        current = head
        while current.next:
            length += 1
            current = current.next
        
        # Calculate the new head position
        k = k % length
        
        # If k is greater than half the length, rotate the list in the opposite direction
        if k > length // 2:
            k = length - k
        
        # Find the new head node
        current = head
        for _ in range(length - k - 1):
            current = current.next
        
        # Break the link between the new head and the old tail
        new_head = current.next
        current.next = None
        
        # Connect the old tail to the new head
        current = head
        while current.next:
            current = current.next
        current.next = head
        
        return new_head
        
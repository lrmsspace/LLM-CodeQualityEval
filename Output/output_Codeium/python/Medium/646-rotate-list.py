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
        if not head or not head.next or k == 0:
            return head

        # Compute the length of the list
        length = 1
        tail = head
        while tail.next:
            tail = tail.next
            length += 1

        # Make the list circular
        tail.next = head

        # Find the new tail: (length - k % length - 1)th node
        # and the new head: (length - k % length)th node
        k = k % length
        new_tail = head
        for _ in range(length - k - 1):
            new_tail = new_tail.next
        new_head = new_tail.next

        # Break the circle
        new_tail.next = None

        return new_head


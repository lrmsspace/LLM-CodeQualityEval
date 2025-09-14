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
        if not head:
            return None
        if k == 0:
            return head
        length = 1
        tail = head
        while tail.next:
            tail = tail.next
            length += 1
        k = k % length
        if k == 0:
            return head
        newTail = head
        for i in range(length - k - 1):
            newTail = newTail.next
        newHead = newTail.next
        newTail.next = None
        tail.next = head
        return newHead
        
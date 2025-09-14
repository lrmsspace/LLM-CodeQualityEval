#https://leetcode.com/problems/remove-duplicates-from-sorted-list/
#Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
# 
#Example 1:
#Input: head = [1,1,2]
#Output: [1,2]
#Example 2:
#Input: head = [1,1,2,3,3]
#Output: [1,2,3]
# 
#Constraints:
#	The number of nodes in the list is in the range [0, 300].
#	-100 <= Node.val <= 100
#	The list is guaranteed to be sorted in ascending order.
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not head or not head.next:
            return head
        
        dummy = ListNode(0)
        dummy.next = head
        
        current = dummy
        
        while current.next and current.next.next:
            if current.next.val == current.next.next.val:
                while current.next and current.next.val == current.next.next.val:
                    current.next = current.next.next
            else:
                current = current.next
        
        return dummy.next
        
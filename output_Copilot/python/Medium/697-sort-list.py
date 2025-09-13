#https://leetcode.com/problems/sort-list/
#Given the head of a linked list, return the list after sorting it in ascending order.
# 
#Example 1:
#Input: head = [4,2,1,3]
#Output: [1,2,3,4]
#Example 2:
#Input: head = [-1,5,3,4,0]
#Output: [-1,0,3,4,5]
#Example 3:
#Input: head = []
#Output: []
# 
#Constraints:
#	The number of nodes in the list is in the range [0, 5 * 104].
#	-105 <= Node.val <= 105
# 
#Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def sortList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not head or not head.next:
            return head

        # Find the middle of the linked list using the slow and fast pointer approach
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # Split the linked list into two halves
        mid = slow
        left = head
        right = mid.next
        mid.next = None

        # Recursively sort the two halves
        left_sorted = self.sortList(left)
        right_sorted = self.sortList(right)

        # Merge the sorted halves
        return self.merge(left_sorted, right_sorted)        
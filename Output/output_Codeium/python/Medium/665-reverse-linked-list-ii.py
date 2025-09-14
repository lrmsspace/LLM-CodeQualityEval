#https://leetcode.com/problems/reverse-linked-list-ii/
#Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
# 
#Example 1:
#Input: head = [1,2,3,4,5], left = 2, right = 4
#Output: [1,4,3,2,5]
#Example 2:
#Input: head = [5], left = 1, right = 1
#Output: [5]
# 
#Constraints:
#	The number of nodes in the list is n.
#	1 <= n <= 500
#	-500 <= Node.val <= 500
#	1 <= left <= right <= n
# 
#Follow up: Could you do it in one pass?
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: Optional[ListNode]
        :type left: int
        :type right: int
        :rtype: Optional[ListNode]
        """
        if not head or left == right:
            return head

        dummy = ListNode(0)
        dummy.next = head
        prev = dummy

        for _ in range(left - 1):
            prev = prev.next

        current = prev.next
        reverse = None

        for _ in range(right - left + 1):
            next_node = current.next
            current.next = reverse
            reverse = current
            current = next_node

        prev.next.next = current
        prev.next = reverse

        return dummy.next

    
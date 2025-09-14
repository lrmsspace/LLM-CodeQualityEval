#https://leetcode.com/problems/partition-list/
#Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
#You should preserve the original relative order of the nodes in each of the two partitions.
# 
#Example 1:
#Input: head = [1,4,3,2,5,2], x = 3
#Output: [1,2,2,4,3,5]
#Example 2:
#Input: head = [2,1], x = 2
#Output: [1,2]
# 
#Constraints:
#	The number of nodes in the list is in the range [0, 200].
#	-100 <= Node.val <= 100
#	-200 <= x <= 200
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def partition(self, head, x):
        """
        :type head: Optional[ListNode]
        :type x: int
        :rtype: Optional[ListNode]
        """
        head1 = ListNode(0)
        head2 = ListNode(0)
        p1 = head1
        p2 = head2
        while head:
            if head.val < x:
                p1.next = head
                p1 = p1.next
            else:
                p2.next = head
                p2 = p2.next
            head = head.next
        p2.next = None
        p1.next = head2.next
        return head1.next
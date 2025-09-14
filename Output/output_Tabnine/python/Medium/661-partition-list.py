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
        # Initialize two pointers:
        # prev_less_than_x: points to the last node less than x
        # prev_greater_than_or_equal_to_x: points to the last node greater than or equal to x
        prev_less_than_x, prev_greater_than_or_equal_to_x = None, None
        
        # Traverse the linked list
        current = head
        while current:
            next_node = current.next
            
            # If current node's value is less than x,
            # update prev_less_than_x and move current to the next node
            if current.val < x:
                if prev_less_than_x:
                    prev_less_than_x.next = current
                else:
                    head = current
                prev_less_than_x = current
            else:
                # If current node's value is greater than or equal to x,
                # update prev_greater_than_or_equal_to_x and move current to the next node
                if prev_greater_than_or_equal_to_x:
                    prev_greater_than_or_equal_to_x.next = current
                prev_greater_than_or_equal_to_x = current
            
            current = next_node
        
        # After the traversal, if prev_greater_than_or_equal_to_x exists,
        # connect it to the end of the list
        if prev_greater_than_or_equal_to_x:
            prev_greater_than_or_equal_to_x.next = None
        
        return head
        
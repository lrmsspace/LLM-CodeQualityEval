#https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
#Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
#After doing so, return the head of the final linked list.  You may return any such answer.
# 
#(Note that in the examples below, all sequences are serializations of ListNode objects.)
#Example 1:
#Input: head = [1,2,-3,3,1]
#Output: [3,1]
#Note: The answer [1,2,1] would also be accepted.
#Example 2:
#Input: head = [1,2,3,-3,4]
#Output: [1,2,4]
#Example 3:
#Input: head = [1,2,3,-3,-2]
#Output: [1]
# 
#Constraints:
#	The given linked list will contain between 1 and 1000 nodes.
#	Each node in the linked list has -1000 <= node.val <= 1000.
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeZeroSumSublists(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        dummy = ListNode(0)
        dummy.next = head
        curr = dummy
        prev_sum = 0
        
        while curr:
            curr_sum = 0
            while curr and curr_sum + curr.val!= prev_sum:
                curr_sum += curr.val
                curr = curr.next
            
            if curr:
                prev_sum = curr_sum + curr.val
                next_node = curr.next
                while next_node and next_node.val == curr.val:
                    next_node = next_node.next
                curr.next = next_node
        
        return dummy.next
        
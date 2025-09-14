#https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
#You are given the head of a linked list, and an integer k.
#Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
# 
#Example 1:
#Input: head = [1,2,3,4,5], k = 2
#Output: [1,4,3,2,5]
#Example 2:
#Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
#Output: [7,9,6,6,8,7,3,0,9,5]
# 
#Constraints:
#	The number of nodes in the list is n.
#	1 <= k <= n <= 105
#	0 <= Node.val <= 100
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapNodes(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        # Find the kth node from the end
        slow, fast = head, head
        for _ in range(k - 1):
            fast = fast.next
            if fast is None:
                return head
        
        prev_kth_end = None
        while fast.next:
            prev_kth_end = slow
            slow = slow.next
            fast = fast.next
        
        # Swap values of the kth node from the beginning and the kth node from the end
        prev_kth_end.next = slow.next
        slow.next = head
        head = slow
        
        return head
        
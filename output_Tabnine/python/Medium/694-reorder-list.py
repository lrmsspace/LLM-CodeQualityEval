#https://leetcode.com/problems/reorder-list/
#You are given the head of a singly linked-list. The list can be represented as:
#L0 → L1 → … → Ln - 1 → Ln
#Reorder the list to be on the following form:
#L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
#You may not modify the values in the list's nodes. Only nodes themselves may be changed.
# 
#Example 1:
#Input: head = [1,2,3,4]
#Output: [1,4,2,3]
#Example 2:
#Input: head = [1,2,3,4,5]
#Output: [1,5,2,4,3]
# 
#Constraints:
#	The number of nodes in the list is in the range [1, 5 * 104].
#	1 <= Node.val <= 1000
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reorderList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: None Do not return anything, modify head in-place instead.
        """
        
        if not head or not head.next:
            return
        
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        mid = slow.next
        slow.next = None
        
        # Reverse the second half of the list
        prev, curr = None, mid
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        
        # Merge the two halves
        curr_first, curr_second = head, prev
        while curr_second:
            next_first_next = curr_first.next
            next_second_next = curr_second.next
            
            curr_first.next = curr_second
            curr_second.next = next_first_next
            
            curr_first = next_first_next
            curr_second = next_second_next
        
        return head
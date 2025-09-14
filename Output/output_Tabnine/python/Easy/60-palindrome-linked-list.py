#https://leetcode.com/problems/palindrome-linked-list/
#Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
# 
#Example 1:
#Input: head = [1,2,2,1]
#Output: true
#Example 2:
#Input: head = [1,2]
#Output: false
# 
#Constraints:
#	The number of nodes in the list is in the range [1, 105].
#	0 <= Node.val <= 9
# 
#Follow up: Could you do it in O(n) time and O(1) space?
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: bool
        """
        # Step 1: Find the middle of the linked list
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        # Step 2: Reverse the second half of the linked list
        prev = None
        curr = slow
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        
        # Step 3: Compare the reversed second half with the first half
        first_half = head
        second_half = prev
        while first_half and second_half:
            if first_half.val!= second_half.val:
                return False
            first_half = first_half.next
            second_half = second_half.next
        
        return True
        
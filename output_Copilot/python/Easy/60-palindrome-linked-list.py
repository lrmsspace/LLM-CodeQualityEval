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
        # 快慢指针找到中点
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # 反转后半部分链表
        prev = None
        while slow:
            next_node = slow.next
            slow.next = prev
            prev = slow
            slow = next_node

        # 比较前半部分和后半部分
        left, right = head, prev
        while right:    
            if left.val != right.val:
                return False
            left = left.next
            right = right.next
        return True    
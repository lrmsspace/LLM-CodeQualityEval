#https://leetcode.com/problems/linked-list-cycle/
#Given head, the head of a linked list, determine if the linked list has a cycle in it.
#There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
#Return true if there is a cycle in the linked list. Otherwise, return false.
# 
#Example 1:
#Input: head = [3,2,0,-4], pos = 1
#Output: true
#Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
#Example 2:
#Input: head = [1,2], pos = 0
#Output: true
#Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
#Example 3:
#Input: head = [1], pos = -1
#Output: false
#Explanation: There is no cycle in the linked list.
# 
#Constraints:
#	The number of the nodes in the list is in the range [0, 104].
#	-105 <= Node.val <= 105
#	pos is -1 or a valid index in the linked-list.
# 
#Follow up: Can you solve it using O(1) (i.e. constant) memory?
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # If the linked list is empty or does not have a cycle, return False
        if not head or not head.next:
            return False
        
        # Initialize two pointers: slow and fast
        slow = head
        fast = head.next
        
        # Traverse the linked list using the slow and fast pointers
        while slow!= fast:
            # If the fast pointer reaches the end of the list or encounters a null pointer, return False
            if not fast or not fast.next:
                return False
            
            # Move the slow pointer one step forward and the fast pointer two steps forward
            slow = slow.next
            fast = fast.next.next
        
        # If the slow pointer and fast pointer meet at the same node, return True
        return True
        
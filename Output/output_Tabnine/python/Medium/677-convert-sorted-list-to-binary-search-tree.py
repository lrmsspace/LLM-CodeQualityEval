#https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
#Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.
# 
#Example 1:
#Input: head = [-10,-3,0,5,9]
#Output: [0,-3,9,-10,null,5]
#Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
#Example 2:
#Input: head = []
#Output: []
# 
#Constraints:
#	The number of nodes in head is in the range [0, 2 * 104].
#	-105 <= Node.val <= 105
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[TreeNode]
        """
        # Base case: if the list is empty, return None
        if not head:
            return None
        
        # Find the middle node of the list
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        # The middle node becomes the root of the subtree
        root = TreeNode(slow.val)
        
        # Recursively build the left and right subtrees
        root.left = self.sortedListToBST(head)
        root.right = self.sortedListToBST(slow.next)
        
        return root
        
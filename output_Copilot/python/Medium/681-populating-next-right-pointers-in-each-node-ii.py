#https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
#Given a binary tree
#struct Node {
#  int val;
#  Node *left;
#  Node *right;
#  Node *next;
#}
#Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
#Initially, all next pointers are set to NULL.
# 
#Example 1:
#Input: root = [1,2,3,4,5,null,7]
#Output: [1,#,2,3,#,4,5,7,#]
#Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
#Example 2:
#Input: root = []
#Output: []
# 
#Constraints:
#	The number of nodes in the tree is in the range [0, 6000].
#	-100 <= Node.val <= 100
# 
#Follow-up:
#	You may only use constant extra space.
#	The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
# Definition for a Node.
class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if not root:
            return None

        # Initialize the current level with the root node
        current_level = [root]

        # Iterate until there are no more nodes at the current level
        while current_level:
            next_level = []
            prev_node = None
            # Iterate through the nodes at the current level
            for node in current_level:
                # If there is a previous node, set its next pointer to the current node
                if prev_node:
                    prev_node.next = node
                # Update the previous node to the current node
                prev_node = node
                # Add the left and right children to the next level list
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            # Move to the next level
            current_level = next_level

        return root
# The code defines a class Solution with a method connect that populates the next right pointers in each node of a binary tree. It uses a level-order traversal approach to connect nodes at each level. The method returns the root of the modified tree.
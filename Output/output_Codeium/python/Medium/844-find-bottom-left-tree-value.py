#https://leetcode.com/problems/find-bottom-left-tree-value/
#Given the root of a binary tree, return the leftmost value in the last row of the tree.
# 
#Example 1:
#Input: root = [2,1,3]
#Output: 1
#Example 2:
#Input: root = [1,2,3,4,null,5,6,null,null,7]
#Output: 7
# 
#Constraints:
#	The number of nodes in the tree is in the range [1, 104].
#	-231 <= Node.val <= 231 - 1
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        from collections import deque
        
        # Perform a level-order traversal (BFS)
        queue = deque([root])
        while queue:
            node = queue.popleft()
            # Add right child first to ensure leftmost node is last at current level
            if node.right:
                queue.append(node.right)
            if node.left:
                queue.append(node.left)
        
        # The last node processed in the BFS is the leftmost node of the last row
        return node.val


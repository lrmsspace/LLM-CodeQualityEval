#https://leetcode.com/problems/deepest-leaves-sum/
#Given the root of a binary tree, return the sum of values of its deepest leaves.
# 
#Example 1:
#Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
#Output: 15
#Example 2:
#Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
#Output: 19
# 
#Constraints:
#	The number of nodes in the tree is in the range [1, 104].
#	1 <= Node.val <= 100
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def deepestLeavesSum(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        queue = [root]
        while queue:
            level_size = len(queue)
            total = 0
            for _ in range(level_size):
                node = queue.pop(0)
                total += node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return total

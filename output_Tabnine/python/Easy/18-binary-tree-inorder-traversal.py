#https://leetcode.com/problems/binary-tree-inorder-traversal/
#Given the root of a binary tree, return the inorder traversal of its nodes' values.
# 
#Example 1:
#Input: root = [1,null,2,3]
#Output: [1,3,2]
#Explanation:
#Example 2:
#Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
#Output: [4,2,6,5,7,1,3,9,8]
#Explanation:
#Example 3:
#Input: root = []
#Output: []
#Example 4:
#Input: root = [1]
#Output: [1]
# 
#Constraints:
#	The number of nodes in the tree is in the range [0, 100].
#	-100 <= Node.val <= 100
# 
#Follow up: Recursive solution is trivial, could you do it iteratively?
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        # Initialize the stack and the result list
        stack = []
        result = []
        
        # While the stack is not empty or the root is not None
        while root or stack:
            # If the root is not None, add it to the stack and move to its left child
            while root:
                stack.append(root)
                root = root.left
            
            # If the stack is not empty, pop the top node from the stack
            root = stack.pop()
            
            # Add the popped node's value to the result list
            result.append(root.val)
            
            # Move to the right child of the popped node
            root = root.right
        
        # Return the result list
        return result
        
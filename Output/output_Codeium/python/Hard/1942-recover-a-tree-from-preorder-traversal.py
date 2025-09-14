#https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
#We run a preorder depth-first search (DFS) on the root of a binary tree.
#At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
#If a node has only one child, that child is guaranteed to be the left child.
#Given the output traversal of this traversal, recover the tree and return its root.
# 
#Example 1:
#Input: traversal = "1-2--3--4-5--6--7"
#Output: [1,2,5,3,4,6,7]
#Example 2:
#Input: traversal = "1-2--3---4-5--6---7"
#Output: [1,2,5,3,null,6,null,4,null,7]
#Example 3:
#Input: traversal = "1-401--349---90--88"
#Output: [1,401,null,349,88,90]
# 
#Constraints:
#	The number of nodes in the original tree is in the range [1, 1000].
#	1 <= Node.val <= 109
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def recoverFromPreorder(self, traversal):
        """
        :type traversal: str
        :rtype: Optional[TreeNode]
        """
        values = []
        i = 0
        while i < len(traversal):
            if traversal[i] == '-':
                i += 1
                continue
            j = i
            while j < len(traversal) and traversal[j] != '-':
                j += 1
            values.append(int(traversal[i:j]))
            i = j
        root = TreeNode(values[0])
        stack = [root]
        i = 1
        while i < len(values):
            node = TreeNode(values[i])
            if len(stack[-1].left) == 0:
                stack[-1].left = node
            else:
                stack[-1].right = node
                stack.pop()
            stack.append(node)
            i += 1
        return root

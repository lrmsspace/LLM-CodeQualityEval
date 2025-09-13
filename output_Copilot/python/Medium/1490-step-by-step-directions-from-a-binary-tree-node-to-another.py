#https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
#You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.
#Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:
#	'L' means to go from a node to its left child node.
#	'R' means to go from a node to its right child node.
#	'U' means to go from a node to its parent node.
#Return the step-by-step directions of the shortest path from node s to node t.
# 
#Example 1:
#Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
#Output: "UURL"
#Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
#Example 2:
#Input: root = [2,1], startValue = 2, destValue = 1
#Output: "L"
#Explanation: The shortest path is: 2 → 1.
# 
#Constraints:
#	The number of nodes in the tree is n.
#	2 <= n <= 105
#	1 <= Node.val <= n
#	All the values in the tree are unique.
#	1 <= startValue, destValue <= n
#	startValue != destValue
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def getDirections(self, root, startValue, destValue):
        """
        :type root: Optional[TreeNode]
        :type startValue: int
        :type destValue: int
        :rtype: str
        """
        # Find the path from the root to the start node and the destination node
        def find_path(root, target, path):
            if not root:
                return False
            path.append(root.val)
            if root.val == target:
                return True
            if find_path(root.left, target, path) or find_path(root.right, target, path):
                return True
            path.pop()
            return False
        
        start_path = []
        dest_path = []
        find_path(root, startValue, start_path)
        find_path(root, destValue, dest_path)
        
        # Find the lowest common ancestor (LCA) of the start and destination nodes
        i = 0
        while i < len(start_path) and i < len(dest_path) and start_path[i] == dest_path[i]:
            i += 1
        
        # The number of steps to go up from the start node to the LCA
        up_steps = len(start_path) - i
        
        # The number of steps to go down from the LCA to the destination node
        down_steps = len(dest_path) - i
        
        # Create the result string with 'U' for up and 'L'/'R' for down
        result = 'U' * up_steps + 'L' * (down_steps - 1) + 'R' * (down_steps - 1)
        
        return result        
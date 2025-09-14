#https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
#You are given the root of a binary tree and a positive integer k.
#The level sum in the tree is the sum of the values of the nodes that are on the same level.
#Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
#Note that two nodes are on the same level if they have the same distance from the root.
# 
#Example 1:
#Input: root = [5,8,9,2,1,3,7,4,6], k = 2
#Output: 13
#Explanation: The level sums are the following:
#- Level 1: 5.
#- Level 2: 8 + 9 = 17.
#- Level 3: 2 + 1 + 3 + 7 = 13.
#- Level 4: 4 + 6 = 10.
#The 2nd largest level sum is 13.
#Example 2:
#Input: root = [1,2,null,3], k = 1
#Output: 3
#Explanation: The largest level sum is 3.
# 
#Constraints:
#	The number of nodes in the tree is n.
#	2 <= n <= 105
#	1 <= Node.val <= 106
#	1 <= k <= n
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def kthLargestLevelSum(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        def dfs(node, level):
            if not node:
                return
            if len(sums) <= level:
                sums.append(node.val)
            else:
                sums[level] += node.val
            dfs(node.left, level + 1)
            dfs(node.right, level + 1)
        
        sums = []
        dfs(root, 0)
        if k > len(sums):
            return -1
        return sums[-k]

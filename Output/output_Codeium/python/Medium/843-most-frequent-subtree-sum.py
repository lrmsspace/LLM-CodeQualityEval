#https://leetcode.com/problems/most-frequent-subtree-sum/
#Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.
#The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).
# 
#Example 1:
#Input: root = [5,2,-3]
#Output: [2,-3,4]
#Example 2:
#Input: root = [5,2,-5]
#Output: [2]
# 
#Constraints:
#	The number of nodes in the tree is in the range [1, 104].
#	-105 <= Node.val <= 105
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findFrequentTreeSum(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        from collections import Counter, defaultdict
        self.count = Counter()
        self.max_count = 0
        self.ans = []

        def dfs(node):
            if not node:
                return 0
            cur = node.val + dfs(node.left) + dfs(node.right)
            self.count[cur] += 1
            self.max_count = max(self.max_count, self.count[cur])
            return cur

        dfs(root)
        for k, v in self.count.items():
            if v == self.max_count:
                self.ans.append(k)

        return self.ans

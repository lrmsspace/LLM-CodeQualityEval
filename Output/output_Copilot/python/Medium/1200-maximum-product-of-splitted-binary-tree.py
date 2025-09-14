#https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
#Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
#Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
#Note that you need to maximize the answer before taking the mod and not after taking it.
# 
#Example 1:
#Input: root = [1,2,3,4,5,6]
#Output: 110
#Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
#Example 2:
#Input: root = [1,null,2,3,4,null,null,5,6]
#Output: 90
#Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
# 
#Constraints:
#	The number of nodes in the tree is in the range [2, 5 * 104].
#	1 <= Node.val <= 104
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxProduct(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        def dfs(node):
            if not node:
                return 0
            left_sum = dfs(node.left)
            right_sum = dfs(node.right)
            total_sum = left_sum + right_sum + node.val
            self.sums.add(total_sum)
            return total_sum

        self.sums = set()
        total_sum = dfs(root)
        max_product = 0
        for subtree_sum in self.sums:
            product = (total_sum - subtree_sum) * subtree_sum
            max_product = max(max_product, product)
        return max_product % (10**9 + 7)        
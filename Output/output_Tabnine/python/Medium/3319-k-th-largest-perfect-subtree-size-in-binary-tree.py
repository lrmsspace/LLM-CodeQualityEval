# You are given the root of a binary tree and an integer k.
# Return an integer denoting the size of the kth largest perfect binary subtree, or -1 if it doesn't exist.
# A perfect binary tree is a tree where all leaves are on the same level, and every parent has two children.
# Example 1:
# Input: root = [5,3,6,5,2,5,7,1,8,null,null,6,8], k = 2
# Output: 3
# Explanation:
# The roots of the perfect binary subtrees are highlighted in black. Their sizes, in non-increasing order are [3, 3, 1, 1, 1, 1, 1, 1].
# The 2nd largest size is 3.
# Example 2:
# Input: root = [1,2,3,4,5,6,7], k = 1
# Output: 7
# Explanation:
# The sizes of the perfect binary subtrees in non-increasing order are [7, 3, 3, 1, 1, 1, 1]. The size of the largest perfect binary subtree is 7.
# Example 3:
# Input: root = [1,2,3,null,4], k = 3
# Output: -1
# Explanation:
# The sizes of the perfect binary subtrees in non-increasing order are [1, 1]. There are fewer than 3 perfect binary subtrees.
# Constraints:
# The number of nodes in the tree is in the range [1, 2000].
# 1 <= Node.val <= 2000
# 1 <= k <= 1024

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def kthLargestPerfectSubtree(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        def size_and_height(node):
            if not node:
                return 0, 0
            l_size, l_height = size_and_height(node.left)
            r_size, r_height = size_and_height(node.right)
            size = 1 + l_size + r_size
            height = max(l_height, r_height) + 1
            if is_perfect(node, size, height):
                nonlocal max_size
                if size > max_size:
                    max_size = size
                    if max_size == k:
                        return size, height
            return size, height
        
        def is_perfect(node, size, height):
            if not node:
                return True
            if size!= 2 ** height - 1:
                return False
        max_size = 0
        size_and_height(root)
        return max_size if max_size >= k else -1
        
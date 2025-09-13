#https://leetcode.com/problems/recover-binary-search-tree/
#You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
# 
#Example 1:
#Input: root = [1,3,null,null,2]
#Output: [3,1,null,null,2]
#Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
#Example 2:
#Input: root = [3,1,4,null,null,2]
#Output: [2,1,4,null,null,3]
#Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
# 
#Constraints:
#	The number of nodes in the tree is in the range [2, 1000].
#	-231 <= Node.val <= 231 - 1
# 
#Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def recoverTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: None Do not return anything, modify root in-place instead.
        """
        # Morris Traversal
        x = y = pred = predecessor = None
        curr = root

        while curr:
            if curr.left:
                # Find the predecessor of current node
                predecessor = curr.left
                while predecessor.right and predecessor.right != curr:
                    predecessor = predecessor.right

                if not predecessor.right:
                    # Make current as right child of its predecessor
                    predecessor.right = curr
                    curr = curr.left
                else:
                    # Revert the changes made to restore the original tree
                    predecessor.right = None

                    if pred and curr.val < pred.val:
                        y = curr
                        if not x:
                            x = pred

                    pred = curr
                    curr = curr.right
            else:
                if pred and curr.val < pred.val:
                    y = curr
                    if not x:
                        x = pred

                pred = curr
                curr = curr.right

        # Swap the values of the two nodes to recover the BST
        x.val, y.val = y.val, x.val   
#         return root
# The function modifies the tree in-place, so no return is needed
        return None         
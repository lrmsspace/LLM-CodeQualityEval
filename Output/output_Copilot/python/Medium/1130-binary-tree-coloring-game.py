#https://leetcode.com/problems/binary-tree-coloring-game/
#Two players play a turn based game on a binary tree. We are given the root of this binary tree, and the number of nodes n in the tree. n is odd, and each node has a distinct value from 1 to n.
#Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n and y != x. The first player colors the node with value x red, and the second player colors the node with value y blue.
#Then, the players take turns starting with the first player. In each turn, that player chooses a node of their color (red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right child, or parent of the chosen node.)
#If (and only if) a player cannot choose such a node in this way, they must pass their turn. If both players pass their turn, the game ends, and the winner is the player that colored more nodes.
#You are the second player. If it is possible to choose such a y to ensure you win the game, return true. If it is not possible, return false.
# 
#Example 1:
#Input: root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
#Output: true
#Explanation: The second player can choose the node with value 2.
#Example 2:
#Input: root = [1,2,3], n = 3, x = 1
#Output: false
# 
#Constraints:
#	The number of nodes in the tree is n.
#	1 <= x <= n <= 100
#	n is odd.
#	1 <= Node.val <= n
#	All the values of the tree are unique.
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def btreeGameWinningMove(self, root, n, x):
        """
        :type root: Optional[TreeNode]
        :type n: int
        :type x: int
        :rtype: bool
        """
        # 计算节点 x 的子树大小
        def count_subtree(node, x):
            if not node:
                return 0
            if node.val == x:
                left_count = count_subtree(node.left, x)
                right_count = count_subtree(node.right, x)
                self.subtree_size = left_count + right_count + 1
                return self.subtree_size
            else:
                return count_subtree(node.left, x) + count_subtree(node.right, x)

        self.subtree_size = 0
        count_subtree(root, x)

        # 计算剩余节点数量
        remaining_nodes = n - self.subtree_size

        # 判断第二个玩家是否可以赢得游戏
        return max(self.subtree_size, remaining_nodes) > n // 2        
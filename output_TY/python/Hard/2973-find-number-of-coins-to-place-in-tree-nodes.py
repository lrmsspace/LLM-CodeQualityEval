# You are given an undirected tree with n nodes labeled from 0 to n - 1, and rooted at node 0. You are given a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
# You are also given a 0-indexed integer array cost of length n, where cost[i] is the cost assigned to the ith node.
# You need to place some coins on every node of the tree. The number of coins to be placed at node i can be calculated as:
# If size of the subtree of node i is less than 3, place 1 coin.
# Otherwise, place an amount of coins equal to the maximum product of cost values assigned to 3 distinct nodes in the subtree of node i. If this product is negative, place 0 coins.
# Return an array coin of size n such that coin[i] is the number of coins placed at node i.
# Example 1:
# Input: edges = [[0,1],[0,2],[0,3],[0,4],[0,5]], cost = [1,2,3,4,5,6]
# Output: [120,1,1,1,1,1]
# Explanation: For node 0 place 6 * 5 * 4 = 120 coins. All other nodes are leaves with subtree of size 1, place 1 coin on each of them.
# Example 2:
# Input: edges = [[0,1],[0,2],[1,3],[1,4],[1,5],[2,6],[2,7],[2,8]], cost = [1,4,2,3,5,7,8,-4,2]
# Output: [280,140,32,1,1,1,1,1,1]
# Explanation: The coins placed on each node are:
# - Place 8 * 7 * 5 = 280 coins on node 0.
# - Place 7 * 5 * 4 = 140 coins on node 1.
# - Place 8 * 2 * 2 = 32 coins on node 2.
# - All other nodes are leaves with subtree of size 1, place 1 coin on each of them.
# Example 3:
# Input: edges = [[0,1],[0,2]], cost = [1,2,-2]
# Output: [0,1,1]
# Explanation: Node 1 and 2 are leaves with subtree of size 1, place 1 coin on each of them. For node 0 the only possible product of cost is 2 * 1 * -2 = -4. Hence place 0 coins on node 0.
# Constraints:
# 2 <= n <= 2 * 104
# edges.length == n - 1
# edges[i].length == 2
# 0 <= ai, bi < n
# cost.length == n
# 1 <= |cost[i]| <= 104
# The input is generated such that edges represents a valid tree.

class Solution(object):
    def placedCoins(self, edges, cost):
        """
        :type edges: List[List[int]]
        :type cost: List[int]
        :rtype: List[int]
        """python
from collections import defaultdict
import heapq

class Solution(object):
    def placedCoins(self, edges, cost):
        """
        :type edges: List[List[int]]
        :type cost: List[int]
        :rtype: List[int]
        """
        MOD = 10**9 + 7
        n = len(cost)
        tree = defaultdict(list)

        for u, v in edges:
            tree[u].append(v)
            tree[v].append(u)

        res = [0] * n

        def dfs(node, parent):
            # 维护最大的三个正数和最小的两个负数
            max_vals = []  # 用最小堆维护最大的三个数（保留最大的）
            min_vals = []  # 用最大堆维护最小的两个数（保留最小的）

            subtree_size = 1
            for nei in tree[node]:
                if nei == parent:
                    continue
                child_size, child_max_vals, child_min_vals = dfs(nei, node)
                subtree_size += child_size

                # 合并子节点的数值
                for x in child_max_vals:
                    heapq.heappush(max_vals, x)
                    if len(max_vals) > 3:
                        heapq.heappop(max_vals)
                for x in child_min_vals:
                    heapq.heappush(min_vals, -x)
                    if len(min_vals) > 2:
                        heapq.heappop(min_vals)

            # 添加当前节点自己的 cost
            heapq.heappush(max_vals, cost[node])
            if len(max_vals) > 3:
                heapq.heappop(max_vals)
            heapq.heappush(min_vals, -cost[node])
            if len(min_vals) > 2:
                heapq.heappop(min_vals)

            # 计算 coin 数量
            if subtree_size < 3:
                res[node] = 1
            else:
                candidates = []
                if len(max_vals) >= 3:
                    candidates.append(max_vals[0] * max_vals[1] * max_vals[2])
                if len(max_vals) >= 1 and len(min_vals) >= 2:
                    candidates.append(max_vals[-1] * (-min_vals[0]) * (-min_vals[1]))
                max_product = max(candidates) if candidates else 0
                res[node] = max(0, max_product) % MOD

            return subtree_size, max_vals, min_vals

        dfs(0, -1)
        return res
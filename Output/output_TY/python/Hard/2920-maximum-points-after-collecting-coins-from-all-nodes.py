# There exists an undirected tree rooted at node 0 with n nodes labeled from 0 to n - 1. You are given a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given a 0-indexed array coins of size n where coins[i] indicates the number of coins in the vertex i, and an integer k.
# Starting from the root, you have to collect all the coins such that the coins at a node can only be collected if the coins of its ancestors have been already collected.
# Coins at nodei can be collected in one of the following ways:
# Collect all the coins, but you will get coins[i] - k points. If coins[i] - k is negative then you will lose abs(coins[i] - k) points.
# Collect all the coins, but you will get floor(coins[i] / 2) points. If this way is used, then for all the nodej present in the subtree of nodei, coins[j] will get reduced to floor(coins[j] / 2).
# Return the maximum points you can get after collecting the coins from all the tree nodes.
# Example 1:
# Input: edges = [[0,1],[1,2],[2,3]], coins = [10,10,3,3], k = 5
# Output: 11                        
# Explanation: 
# Collect all the coins from node 0 using the first way. Total points = 10 - 5 = 5.
# Collect all the coins from node 1 using the first way. Total points = 5 + (10 - 5) = 10.
# Collect all the coins from node 2 using the second way so coins left at node 3 will be floor(3 / 2) = 1. Total points = 10 + floor(3 / 2) = 11.
# Collect all the coins from node 3 using the second way. Total points = 11 + floor(1 / 2) = 11.
# It can be shown that the maximum points we can get after collecting coins from all the nodes is 11. 
# Example 2:
# Input: edges = [[0,1],[0,2]], coins = [8,4,4], k = 0
# Output: 16
# Explanation: 
# Coins will be collected from all the nodes using the first way. Therefore, total points = (8 - 0) + (4 - 0) + (4 - 0) = 16.
# Constraints:
# n == coins.length
# 2 <= n <= 105
# 0 <= coins[i] <= 104
# edges.length == n - 1
# 0 <= edges[i][0], edges[i][1] < n
# 0 <= k <= 104
class Solution(object):
    def maximumPoints(self, edges, coins, k):
        """
        :type edges: List[List[int]]
        :type coins: List[int]
        :type k: int
        :rtype: int
        """
        from collections import defaultdict
        
        MOD = 10 ** 9 + 7
        n = len(coins)
        
        # 构建图的邻接表
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = [False] * n

        def dfs(u):
            visited[u] = True
            
            # dp[0]: 当前节点使用方式一的最大得分
            # dp[1]: 当前节点使用方式二的最大得分
            dp = [0, 0]

            # 方式一：收集当前节点，得分为 coins[u] - k
            score1 = coins[u] - k
            for v in graph[u]:
                if not visited[v]:
                    child_dp = dfs(v)
                    dp[0] += max(child_dp[0], child_dp[1])

            dp[0] += score1

            # 方式二：收集当前节点，得分为 coins[u] // 2
            # 同时子节点的硬币都要减半
            score2 = coins[u] // 2
            for v in graph[u]:
                if not visited[v]:
                    child_coins_half = coins[v] // 2
                    # 子节点可以选择方式一或方式二，但它们的硬币已经减半
                    child_dp_half = dfs_with_coin_value(v, child_coins_half)
                    dp[1] += max(child_dp_half[0], child_dp_half[1])

            dp[1] += score2

            return dp

        def dfs_with_coin_value(u, coin_val):
            """辅助DFS函数，在父节点使用方式二时调用，传入减半后的硬币值"""
            visited[u] = True

            dp = [0, 0]

            # 方式一：使用 coin_val - k
            score1 = coin_val - k
            for v in graph[u]:
                if not visited[v]:
                    child_dp = dfs_with_coin_value(v, coins[v] // 2)
                    dp[0] += max(child_dp[0], child_dp[1])

            dp[0] += score1

            # 方式二：使用 coin_val // 2
            score2 = coin_val // 2
            for v in graph[u]:
                if not visited[v]:
                    child_dp = dfs_with_coin_value(v, coins[v] // 2)
                    dp[1] += max(child_dp[0], child_dp[1])

            dp[1] += score2

            return dp

        result_dp = dfs(0)
        return max(result_dp[0], result_dp[1])    
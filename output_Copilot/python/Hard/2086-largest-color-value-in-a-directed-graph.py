#https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
#There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
#You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
#A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
#Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
# 
#Example 1:
#Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
#Output: 3
#Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
#Example 2:
#Input: colors = "a", edges = [[0,0]]
#Output: -1
#Explanation: There is a cycle from 0 to 0.
# 
#Constraints:
#	n == colors.length
#	m == edges.length
#	1 <= n <= 105
#	0 <= m <= 105
#	colors consists of lowercase English letters.
#	0 <= aj, bj < n
class Solution(object):

    def largestPathValue(self, colors, edges):

        """

        :type colors: str

        :type edges: List[List[int]]

        :rtype: int

        """
        # 1. 构建邻接表和入度数组
        n = len(colors)
        graph = defaultdict(list)
        indegree = [0] * n
        for u, v in edges:
            graph[u].append(v)
            indegree[v] += 1

        # 2. 拓扑排序
        queue = deque()
        for i in range(n):
            if indegree[i] == 0:
                queue.append(i)

        # 3. dp 数组，dp[i][j] 表示到达节点 i 时颜色 j 的最大值
        dp = [[0] * 26 for _ in range(n)]
        for i in range(n):
            dp[i][ord(colors[i]) - ord('a')] += 1

        # 4. 拓扑排序 + 动态规划
        ans = 0
        while queue:
            node = queue.popleft()
            ans = max(ans, max(dp[node]))
            for neighbor in graph[node]:
                for j in range(26):
                    dp[neighbor][j] = max(dp[neighbor][j], dp[node][j])
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)

        # 5. 检查是否有环
        if sum(indegree) > 0:
            return -1

        return ans
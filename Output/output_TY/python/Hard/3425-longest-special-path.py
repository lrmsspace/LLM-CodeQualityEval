# You are given an undirected tree rooted at node 0 with n nodes numbered from 0 to n - 1, represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi, lengthi] indicates an edge between nodes ui and vi with length lengthi. You are also given an integer array nums, where nums[i] represents the value at node i.
# A special path is defined as a downward path from an ancestor node to a descendant node such that all the values of the nodes in that path are unique.
# Note that a path may start and end at the same node.
# Return an array result of size 2, where result[0] is the length of the longest special path, and result[1] is the minimum number of nodes in all possible longest special paths.
# Example 1:
# Input: edges = [[0,1,2],[1,2,3],[1,3,5],[1,4,4],[2,5,6]], nums = [2,1,2,1,3,1]
# Output: [6,2]
# Explanation:
# In the image below, nodes are colored by their corresponding values in nums
# The longest special paths are 2 -> 5 and 0 -> 1 -> 4, both having a length of 6. The minimum number of nodes across all longest special paths is 2.
# Example 2:
# Input: edges = [[1,0,8]], nums = [2,2]
# Output: [0,1]
# Explanation:
# The longest special paths are 0 and 1, both having a length of 0. The minimum number of nodes across all longest special paths is 1.
# Constraints:
# 2 <= n <= 5 * 104
# edges.length == n - 1
# edges[i].length == 3
# 0 <= ui, vi < n
# 1 <= lengthi <= 103
# nums.length == n
# 0 <= nums[i] <= 5 * 104
# The input is generated such that edges represents a valid tree.

class Solution(object):
    def longestSpecialPath(self, edges, nums):
        """
        :type edges: List[List[int]]
        :type nums: List[int]
        :rtype: List[int]
        """
        from collections import defaultdict
        
        # 构建图的邻接表
        graph = defaultdict(list)
        for u, v, length in edges:
            graph[u].append((v, length))
            graph[v].append((u, length))
        
        # 记录最长路径和对应的最少节点数
        max_length = 0
        count_paths_with_max_length = 0
        
        # 深度优先搜索函数
        def dfs(node, parent, value_set):
            nonlocal max_length, count_paths_with_max_length
            
            # 如果当前节点值已存在，则停止搜索
            if nums[node] in value_set:
                return 0
            
            # 添加当前节点值到集合中
            value_set.add(nums[node])
            
            # 当前节点作为结束点的路径长度（自身长度为0）
            current_max = 0
            
            # 记录子节点返回的最大长度
            first_max = 0
            second_max = 0
            
            # 遍历所有相邻节点
            for neighbor, length in graph[node]:
                if neighbor != parent:
                    child_length = dfs(neighbor, node, value_set)
                    if child_length >= first_max:
                        second_max = first_max
                        first_max = child_length
                    elif child_length > second_max:
                        second_max = child_length
            
            # 计算通过当前节点的最长路径
            current_path_length = first_max + second_max
            
            # 更新全局最长路径
            if current_path_length > max_length:
                max_length = current_path_length
                count_paths_with_max_length = 1
            elif current_path_length == max_length:
                count_paths_with_max_length += 1
            
            # 回溯：从集合中移除当前节点值
            value_set.remove(nums[node])
            
            # 返回当前节点向上的最大路径长度
            return first_max
        
        # 执行DFS
        for i in range(len(nums)):
            visited_values = set()
            dfs(i, -1, visited_values)
        
        return [max_length, count_paths_with_max_length]
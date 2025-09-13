#https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
#There are n items each belonging to zero or one of m groups where group[i] is the group that the i-th item belongs to and it's equal to -1 if the i-th item belongs to no group. The items and the groups are zero indexed. A group can have no item belonging to it.
#Return a sorted list of the items such that:
#	The items that belong to the same group are next to each other in the sorted list.
#	There are some relations between these items where beforeItems[i] is a list containing all the items that should come before the i-th item in the sorted array (to the left of the i-th item).
#Return any solution if there is more than one solution and return an empty list if there is no solution.
# 
#Example 1:
#Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3,6],[],[],[]]
#Output: [6,3,4,1,5,2,0,7]
#Example 2:
#Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
#Output: []
#Explanation: This is the same as example 1 except that 4 needs to be before 6 in the sorted list.
# 
#Constraints:
#	1 <= m <= n <= 3 * 104
#	group.length == beforeItems.length == n
#	-1 <= group[i] <= m - 1
#	0 <= beforeItems[i].length <= n - 1
#	0 <= beforeItems[i][j] <= n - 1
#	i != beforeItems[i][j]
#	beforeItems[i] does not contain duplicates elements.
class Solution(object):
    def sortItems(self, n, m, group, beforeItems):
        """
        :type n: int
        :type m: int
        :type group: List[int]
        :type beforeItems: List[List[int]]
        :rtype: List[int]
        """
        def dfs(node, graph, visited, stack):
            visited[node] = True
            for neighbor in graph[node]:
                if not visited[neighbor]:
                    dfs(neighbor, graph, visited, stack)
            stack.append(node)

        def topological_sort(graph):
            visited = [False] * len(graph)
            stack = []
            for i in range(len(graph)):
                if not visited[i]:
                    dfs(i, graph, visited, stack)
            return stack[::-1]

        # Step 1: Assign groups to items
        group_map = {}
        group_id = m
        for i in range(n):
            if group[i] == -1:
                group[i] = group_id
                group_map[group_id] = []
                group_id += 1
            group_map[group[i]].append(i)

        # Step 2: Build the graph for items and groups
        item_graph = [[] for _ in range(n)]
        group_graph = [[] for _ in range(group_id)]
        for i in range(n):
            for before_item in beforeItems[i]:
                item_graph[before_item].append(i)
                if group[i] != group[before_item]:
                    group_graph[group[before_item]].append(group[i])

        # Step 3: Topological sort for items and groups
        item_order = topological_sort(item_graph)
        group_order = topological_sort(group_graph)

        # Step 4: Build the result list
        result = []
        for g in group_order:
            result.extend(group_map[g])

        return result if len(result) == n else []        
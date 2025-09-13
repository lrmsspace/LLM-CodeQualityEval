#https://leetcode.com/problems/network-delay-time/
#You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
#We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
# 
#Example 1:
#Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
#Output: 2
#Example 2:
#Input: times = [[1,2,1]], n = 2, k = 1
#Output: 1
#Example 3:
#Input: times = [[1,2,1]], n = 2, k = 2
#Output: -1
# 
#Constraints:
#	1 <= k <= n <= 100
#	1 <= times.length <= 6000
#	times[i].length == 3
#	1 <= ui, vi <= n
#	ui != vi
#	0 <= wi <= 100
#	All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
class Solution(object):
    def networkDelayTime(self, times, n, k):
        """
        :type times: List[List[int]]
        :type n: int
        :type k: int
        :rtype: int
        """
        graph = {i: [] for i in range(1, n+1)}
        for u, v, w in times:
            graph[u].append((v, w))
        
        visited = set()
        distances = {i: float('inf') for i in range(1, n+1)}
        distances[k] = 0
        
        while visited!= set(range(1, n+1)):
            min_distance = float('inf')
            min_node = None
            for node in visited:
                if distances[node] < min_distance:
                    min_distance = distances[node]
                    min_node = node
            
            visited.add(min_node)
            
            for neighbor, weight in graph[min_node]:
                if neighbor not in visited:
                    distances[neighbor] = min(distances[neighbor], distances[min_node] + weight)
        
        return max(distances.values()) if max(distances.values())!= float('inf') else -1
        
#https://leetcode.com/problems/bus-routes/
#You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.
#	For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
#You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.
#Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.
# 
#Example 1:
#Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
#Output: 2
#Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
#Example 2:
#Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
#Output: -1
# 
# 
#Constraints:
#	1 <= routes.length <= 500.
#	1 <= routes[i].length <= 105
#	All the values of routes[i] are unique.
#	sum(routes[i].length) <= 105
#	0 <= routes[i][j] < 106
#	0 <= source, target < 106
class Solution(object):
    def numBusesToDestination(self, routes, source, target):
        """
        :type routes: List[List[int]]
        :type source: int
        :type target: int
        :rtype: int
        """
        # Create a graph where each node represents a bus stop, and there is an edge between two nodes if there is a bus that stops at both nodes.
        graph = collections.defaultdict(set)
        for route in routes:
            for i in range(len(route) - 1):
                graph[route[i]].add(route[i + 1])
                graph[route[i + 1]].add(route[i])
        
        # Use BFS to find the shortest path from the source bus stop to the target bus stop.
        queue = collections.deque([(source, 0)])
        visited = set([source])
        
        while queue:
            bus, stops = queue.popleft()
            if bus == target:
                return stops
            
            for neighbor in graph[bus]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append((neighbor, stops + 1))
        
        return -1
        
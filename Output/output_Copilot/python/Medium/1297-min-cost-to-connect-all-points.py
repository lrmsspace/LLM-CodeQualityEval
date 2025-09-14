#https://leetcode.com/problems/min-cost-to-connect-all-points/
#You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
#The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
#Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
# 
#Example 1:
#Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
#Output: 20
#Explanation: 
#We can connect the points as shown above to get the minimum cost of 20.
#Notice that there is a unique path between every pair of points.
#Example 2:
#Input: points = [[3,12],[-2,5],[-4,1]]
#Output: 18
# 
#Constraints:
#	1 <= points.length <= 1000
#	-106 <= xi, yi <= 106
#	All pairs (xi, yi) are distinct.
class Solution(object):
    def minCostConnectPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        # Prim's algorithm to find the minimum spanning tree (MST)
        n = len(points)
        visited = [False] * n
        min_heap = [(0, 0)]   
        total_cost = 0
        edges = 0   
        while edges < n:
            cost, point = heapq.heappop(min_heap)
            if visited[point]:
                continue
            visited[point] = True
            total_cost += cost
            edges += 1
            for i in range(n):
                if not visited[i]:
                    dist = abs(points[point][0] - points[i][0]) + abs(points[point][1] - points[i][1])
                    heapq.heappush(min_heap, (dist, i))
        return total_cost        
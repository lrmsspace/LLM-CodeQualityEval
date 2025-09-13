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
        n = len(points)
        edges = []
        for i in range(n):
            for j in range(i+1, n):
                dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
                edges.append((dis, i, j))
        edges.sort()
        parent = list(range(n))
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        def union(x, y):
            rootx = find(x)
            rooty = find(y)
            if rootx != rooty:
                parent[rootx] = rooty
        res = 0
        for edge in edges:
            dis, x, y = edge
            if find(x) != find(y):
                union(x, y)
                res += dis
        return res

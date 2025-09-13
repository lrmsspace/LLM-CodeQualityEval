# You are given an integer side, representing the edge length of a square with corners at (0, 0), (0, side), (side, 0), and (side, side) on a Cartesian plane.
# You are also given a positive integer k and a 2D integer array points, where points[i] = [xi, yi] represents the coordinate of a point lying on the boundary of the square.
# You need to select k elements among points such that the minimum Manhattan distance between any two points is maximized.
# Return the maximum possible minimum Manhattan distance between the selected k points.
# The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
# Example 1:
# Input: side = 2, points = [[0,2],[2,0],[2,2],[0,0]], k = 4
# Output: 2
# Explanation:
# Select all four points.
# Example 2:
# Input: side = 2, points = [[0,0],[1,2],[2,0],[2,2],[2,1]], k = 4
# Output: 1
# Explanation:
# Select the points (0, 0), (2, 0), (2, 2), and (2, 1).
# Example 3:
# Input: side = 2, points = [[0,0],[0,1],[0,2],[1,2],[2,0],[2,2],[2,1]], k = 5
# Output: 1
# Explanation:
# Select the points (0, 0), (0, 1), (0, 2), (1, 2), and (2, 2).
# Constraints:
# 1 <= side <= 109
# 4 <= points.length <= min(4 * side, 15 * 103)
# points[i] == [xi, yi]
# The input is generated such that:
# points[i] lies on the boundary of the square.
# All points[i] are unique.
# 4 <= k <= min(25, points.length)

class Solution(object):
    def maxDistance(self, side, points, k):
        """
        :type side: int
        :type points: List[List[int]]
        :type k: int
        :rtype: int
        """
        # Sort the points based on their Manhattan distance from the center of the square
        points.sort(key=lambda p: abs(side // 2 - p[0]) + abs(side // 2 - p[1]))
        
        # Initialize the maximum distance and the current sum
        max_distance = 0
        current_sum = 0
        
        # Iterate over the sorted points and select k points
        for i in range(k):
            current_sum += points[i][0] + points[i][1]
        
        # Update the maximum distance
        max_distance = max(max_distance, current_sum)
        
        # Iterate over the remaining points and update the maximum distance
        for i in range(k, len(points)):
            current_sum += points[i][0] + points[i][1] - points[i - k][0] - points[i - k][1]    
            max_distance = max(max_distance, current_sum)   
        return max_distance
        
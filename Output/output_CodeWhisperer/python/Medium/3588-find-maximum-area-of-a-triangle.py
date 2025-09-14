# You are given a 2D array coords of size n x 2, representing the coordinates of n points in an infinite Cartesian plane.
# Find twice the maximum area of a triangle with its corners at any three elements from coords, such that at least one side of this triangle is parallel to the x-axis or y-axis. Formally, if the maximum area of such a triangle is A, return 2 * A.
# If no such triangle exists, return -1.
# Note that a triangle cannot have zero area.
# Example 1:
# Input: coords = [[1,1],[1,2],[3,2],[3,3]]
# Output: 2
# Explanation:
# The triangle shown in the image has a base 1 and height 2. Hence its area is 1/2 * base * height = 1.
# Example 2:
# Input: coords = [[1,1],[2,2],[3,3]]
# Output: -1
# Explanation:
# The only possible triangle has corners (1, 1), (2, 2), and (3, 3). None of its sides are parallel to the x-axis or the y-axis.
# Constraints:
# 1 <= n == coords.length <= 105
# 1 <= coords[i][0], coords[i][1] <= 106
# All coords[i] are unique.

class Solution(object):
    def maxArea(self, coords):
        """
        :type coords: List[List[int]]
        :rtype: int
        """
        # Sort the coordinates by x-coordinate
        coords.sort(key=lambda x: x[0])
        n = len(coords)
        max_area = 0

        # Iterate through all possible pairs of points
        for i in range(n):
            for j in range(i + 1, n):
                # Check if the triangle formed by these points has a non-zero area
                if coords[i][0] != coords[j][0] and coords[i][1] != coords[j][1]:
                    # Calculate the area of the triangle
                    area = abs(coords[i][0] - coords[j][0]) * abs(coords[i][1] - coords[j][1])
                    max_area = max(max_area, area)

        # Check if there exists a triangle with at least one side parallel to the x-axis or y-axis
        if max_area == 0:
            return -1
        else:
            return 2 * max_area        
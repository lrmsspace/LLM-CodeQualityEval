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
        n = len(coords)
        res = 0
        for i in range(n):
            for j in range(i+1, n):
                for k in range(j+1, n):
                    # check if the side of the triangle is parallel to the x-axis or y-axis
                    if coords[i][0] == coords[j][0] or coords[i][1] == coords[j][1] or coords[j][0] == coords[k][0] or coords[j][1] == coords[k][1]:
                        # calculate the area of the triangle
                        area = abs((coords[i][0] * (coords[j][1] - coords[k][1]) + coords[j][0] * (coords[k][1] - coords[i][1]) + coords[k][0] * (coords[i][1] - coords[j][1])) / 2.0)
                        # update the maximum area
                        res = max(res, area * 2)
        return res if res != 0 else -1

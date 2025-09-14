# You are given a 2D array of integers coordinates of length n and an integer k, where 0 <= k < n.
# coordinates[i] = [xi, yi] indicates the point (xi, yi) in a 2D plane.
# An increasing path of length m is defined as a list of points (x1, y1), (x2, y2), (x3, y3), ..., (xm, ym) such that:
# xi < xi + 1 and yi < yi + 1 for all i where 1 <= i < m.
# (xi, yi) is in the given coordinates for all i where 1 <= i <= m.
# Return the maximum length of an increasing path that contains coordinates[k].
# Example 1:
# Input: coordinates = [[3,1],[2,2],[4,1],[0,0],[5,3]], k = 1
# Output: 3
# Explanation:
# (0, 0), (2, 2), (5, 3) is the longest increasing path that contains (2, 2).
# Example 2:
# Input: coordinates = [[2,1],[7,0],[5,6]], k = 2
# Output: 2
# Explanation:
# (2, 1), (5, 6) is the longest increasing path that contains (5, 6).
# Constraints:
# 1 <= n == coordinates.length <= 105
# coordinates[i].length == 2
# 0 <= coordinates[i][0], coordinates[i][1] <= 109
# All elements in coordinates are distinct.
# 0 <= k <= n - 1

class Solution(object):
    def maxPathLength(self, coordinates, k):
        """
        :type coordinates: List[List[int]]
        :type k: int
        :rtype: int
        """
        from bisect import bisect_left
        from sortedcontainers import SortedList

        # Sort coordinates by x and then by y
        coordinates.sort()

        # Extract the y-coordinates
        ys = [y for _, y in coordinates]

        # Create a sorted list to maintain the longest increasing subsequence of y-coordinates
        sl = SortedList()
        dp = [0] * len(coordinates)

        for i, y in enumerate(ys):
            pos = bisect_left(sl, y)
            if pos < len(sl):
                sl[pos] = y
            else:
                sl.add(y)
            dp[i] = pos + 1

        # The length of the longest increasing path containing coordinates[k]
        return dp[k]
        
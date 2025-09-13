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

from bisect import bisect_left, bisect_right
from collections import defaultdict
import sys

class Solution(object):
    def maxPathLength(self, coordinates, k):
        """
        :type coordinates: List[List[int]]
        :type k: int
        :rtype: int
        """
        n = len(coordinates)
        target_point = coordinates[k]

        # Step 1: Sort all points by x, then y
        indexed_coords = [(x, y, i) for i, (x, y) in enumerate(coordinates)]
        indexed_coords.sort()

        # Coordinate compression for y values
        ys = [y for x, y, i in indexed_coords]
        unique_ys = sorted(set(ys))
        y_id = {y: idx for idx, y in enumerate(unique_ys)}
        m = len(unique_ys)

        # Fenwick Tree / BIT to support range maximum query
        class BIT:
            def __init__(self, size):
                self.N = size + 10
                self.tree = [-float('inf')] * (self.N)

            def update(self, idx, value):
                idx += 1
                while idx < self.N:
                    self.tree[idx] = max(self.tree[idx], value)
                    idx += idx & -idx

            def query(self, idx):
                res = -float('inf')
                idx += 1
                while idx > 0:
                    res = max(res, self.tree[idx])
                    idx -= idx & -idx
                return res

        bit = BIT(m + 5)
        dp = [1] * n  # dp[i]: length of LIS ending at point i

        for i in range(n):
            x, y, idx = indexed_coords[i]
            y_rank = y_id[y]
            max_len = bit.query(y_rank - 1)
            dp[i] = max(dp[i], max_len + 1)
            bit.update(y_rank, dp[i])

        # Now find the max path length that includes coordinates[k]
        max_len = 0
        target_x, target_y = coordinates[k]
        for i in range(n):
            x, y, idx = indexed_coords[i]
            if idx == k:
                max_len = max(max_len, dp[i])

        return max_len
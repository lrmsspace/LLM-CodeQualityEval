# There are n points on an infinite plane. You are given two integer arrays xCoord and yCoord where (xCoord[i], yCoord[i]) represents the coordinates of the ith point.
# Your task is to find the maximum area of a rectangle that:
# Can be formed using four of these points as its corners.
# Does not contain any other point inside or on its border.
# Has its edges parallel to the axes.
# Return the maximum area that you can obtain or -1 if no such rectangle is possible.
# Example 1:
# Input: xCoord = [1,1,3,3], yCoord = [1,3,1,3]
# Output: 4
# Explanation:
# We can make a rectangle with these 4 points as corners and there is no other point that lies inside or on the border. Hence, the maximum possible area would be 4.
# Example 2:
# Input: xCoord = [1,1,3,3,2], yCoord = [1,3,1,3,2]
# Output: -1
# Explanation:
# There is only one rectangle possible is with points [1,1], [1,3], [3,1] and [3,3] but [2,2] will always lie inside it. Hence, returning -1.
# Example 3:
# Input: xCoord = [1,1,3,3,1,3], yCoord = [1,3,1,3,2,2]
# Output: 2
# Explanation:
# The maximum area rectangle is formed by the points [1,3], [1,2], [3,2], [3,3], which has an area of 2. Additionally, the points [1,1], [1,2], [3,1], [3,2] also form a valid rectangle with the same area.
# Constraints:
# 1 <= xCoord.length == yCoord.length <= 2 * 105
# 0 <= xCoord[i], yCoord[i] <= 8 * 107
# All the given points are unique.

class Solution(object):
    def maxRectangleArea(self, xCoord, yCoord):
        """
        :type xCoord: List[int]
        :type yCoord: List[int]
        :rtype: int
        """
        from collections import defaultdict

        points = set(zip(xCoord, yCoord))
        x_set = sorted(set(xCoord))
        y_set = sorted(set(yCoord))

        max_area = -1
        n = len(x_set)
        m = len(y_set)

        for i in range(n):
            for j in range(i + 1, n):
                x1, x2 = x_set[i], x_set[j]
                y_candidates = []

                for y in y_set:
                    if (x1, y) in points and (x2, y) in points:
                        y_candidates.append(y)

                if len(y_candidates) < 2:
                    continue

                for k in range(len(y_candidates) - 1):
                    for l in range(k + 1, len(y_candidates)):
                        y1, y2 = y_candidates[k], y_candidates[l]
                        area = (x2 - x1) * (y2 - y1)
                        max_area = max(max_area, area)

        return max_area
        
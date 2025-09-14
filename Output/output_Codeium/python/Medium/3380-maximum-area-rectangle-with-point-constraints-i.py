# You are given an array points where points[i] = [xi, yi] represents the coordinates of a point on an infinite plane.
# Your task is to find the maximum area of a rectangle that:
# Can be formed using four of these points as its corners.
# Does not contain any other point inside or on its border.
# Has its edges parallel to the axes.
# Return the maximum area that you can obtain or -1 if no such rectangle is possible.
# Example 1:
# Input: points = [[1,1],[1,3],[3,1],[3,3]]
# Output: 4
# Explanation:
# We can make a rectangle with these 4 points as corners and there is no other point that lies inside or on the border. Hence, the maximum possible area would be 4.
# Example 2:
# Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
# Output: -1
# Explanation:
# There is only one rectangle possible is with points [1,1], [1,3], [3,1] and [3,3] but [2,2] will always lie inside it. Hence, returning -1.
# Example 3:
# Input: points = [[1,1],[1,3],[3,1],[3,3],[1,2],[3,2]]
# Output: 2
# Explanation:
# The maximum area rectangle is formed by the points [1,3], [1,2], [3,2], [3,3], which has an area of 2. Additionally, the points [1,1], [1,2], [3,1], [3,2] also form a valid rectangle with the same area.
# Constraints:
# 1 <= points.length <= 10
# points[i].length == 2
# 0 <= xi, yi <= 100
# All the given points are unique.

class Solution(object):
    def maxRectangleArea(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        xCoord = [point[0] for point in points]
        yCoord = [point[1] for point in points]
        maxArea = 0
        for i in range(len(points)):
            for j in range(i+1, len(points)):
                for k in range(j+1, len(points)):
                    for l in range(k+1, len(points)):
                        if xCoord[i] == xCoord[j] and xCoord[k] == xCoord[l] and yCoord[i] == yCoord[k] and yCoord[j] == yCoord[l]:
                            area = abs(xCoord[i] - xCoord[k]) * abs(yCoord[i] - yCoord[j])
                            isInside = False
                            for point in points:
                                if point != points[i] and point != points[j] and point != points[k] and point != points[l]:
                                    if min(xCoord[i], xCoord[k]) <= point[0] <= max(xCoord[i], xCoord[k]) and min(yCoord[i], yCoord[j]) <= point[1] <= max(yCoord[i], yCoord[j]):
                                        isInside = True
                                        break
                            if not isInside:
                                maxArea = max(maxArea, area)
        return maxArea if maxArea != 0 else -1

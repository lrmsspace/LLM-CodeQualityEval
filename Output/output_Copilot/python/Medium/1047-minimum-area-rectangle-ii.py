#https://leetcode.com/problems/minimum-area-rectangle-ii/
#You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
#Return the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the X and Y axes. If there is not any such rectangle, return 0.
#Answers within 10-5 of the actual answer will be accepted.
# 
#Example 1:
#Input: points = [[1,2],[2,1],[1,0],[0,1]]
#Output: 2.00000
#Explanation: The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.
#Example 2:
#Input: points = [[0,1],[2,1],[1,1],[1,0],[2,0]]
#Output: 1.00000
#Explanation: The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.
#Example 3:
#Input: points = [[0,3],[1,2],[3,1],[1,3],[2,1]]
#Output: 0
#Explanation: There is no possible rectangle to form from these points.
# 
#Constraints:
#	1 <= points.length <= 50
#	points[i].length == 2
#	0 <= xi, yi <= 4 * 104
#	All the given points are unique.
class Solution(object):
    def minAreaFreeRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        # 1. 使用集合存储点的坐标，方便查找
        # 2. 使用字典存储点的坐标和对应的点的坐标
        # 3. 遍历所有点，计算矩形的面积
        # 4. 返回最小矩形的面积
        # 5. 时间复杂度O(n^2)，空间复杂度O(n)
        point_set = set(map(tuple, points))
        min_area = float('inf')
        n = len(points)
        
        for i in range(n):
            for j in range(i + 1, n):
                x1, y1 = points[i]
                x2, y2 = points[j]
                if (x1, y2) in point_set and (x2, y1) in point_set:
                    area = abs(x1 - x2) * abs(y1 - y2)
                    min_area = min(min_area, area)
        
        return min_area if min_area != float('inf') else 0   
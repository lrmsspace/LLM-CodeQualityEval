#https://leetcode.com/problems/perfect-rectangle/
#Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).
#Return true if all the rectangles together form an exact cover of a rectangular region.
# 
#Example 1:
#Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
#Output: true
#Explanation: All 5 rectangles together form an exact cover of a rectangular region.
#Example 2:
#Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
#Output: false
#Explanation: Because there is a gap between the two rectangular regions.
#Example 3:
#Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
#Output: false
#Explanation: Because two of the rectangles overlap with each other.
# 
#Constraints:
#	1 <= rectangles.length <= 2 * 104
#	rectangles[i].length == 4
#	-105 <= xi < ai <= 105
#	-105 <= yi < bi <= 105
class Solution(object):
    def isRectangleCover(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        # 1. 计算所有矩形的面积之和
        area_sum = 0
        # 2. 计算所有矩形的左下角和右上角坐标
        left_bottom = [float('inf'), float('inf')]
        right_top = [float('-inf'), float('-inf')]
        # 3. 计算所有矩形的四个角的坐标出现次数
        corners = {}
        
        for rect in rectangles:
            x1, y1, x2, y2 = rect
            area_sum += (x2 - x1) * (y2 - y1)
            left_bottom[0] = min(left_bottom[0], x1)
            left_bottom[1] = min(left_bottom[1], y1)
            right_top[0] = max(right_top[0], x2)
            right_top[1] = max(right_top[1], y2)
            
            corners[(x1, y1)] = corners.get((x1, y1), 0) + 1
            corners[(x2, y2)] = corners.get((x2, y2), 0) + 1
            corners[(x1, y2)] = corners.get((x1, y2), 0) + 1
            corners[(x2, y1)] = corners.get((x2, y1), 0) + 1
        
        # 4. 检查四个角的坐标出现次数是否为奇数，其他坐标出现次数是否为偶数
        for corner, count in corners.items():
            if corner == (left_bottom[0], left_bottom[1]) or corner == (right_top[0], right_top[1]):
                if count != 1:
                    return False
            else:
                if count % 2 != 0:
                    return False
        
        # 5. 检查面积是否相等
        total_area = (right_top[0] - left_bottom[0]) * (right_top[1] - left_bottom[1])
        
        return area_sum == total_area and len(corners) == len(rectangles) * 4 - 4        
#https://leetcode.com/problems/minimum-area-rectangle/
#You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
#Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.
# 
#Example 1:
#Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
#Output: 4
#Example 2:
#Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
#Output: 2
# 
#Constraints:
#	1 <= points.length <= 500
#	points[i].length == 2
#	0 <= xi, yi <= 4 * 104
#	All the given points are unique.
class Solution(object):
    def minAreaRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        # Create a dictionary to store the points and their corresponding indices
        point_dict = {}
        for i, point in enumerate(points):
            x, y = point
            if x not in point_dict:
                point_dict[x] = {}
            point_dict[x][y] = i
        
        # Initialize the minimum area
        min_area = float('inf')
        
        # Iterate through the x-coordinates in sorted order
        x_coords = sorted(point_dict.keys())
        for i in range(len(x_coords) - 1):
            # Iterate through the y-coordinates of the current x-coordinate
            for j in range(len(point_dict[x_coords[i]])):
                for k in range(j + 1, len(point_dict[x_coords[i]])):
                    # Check if the current pair of y-coordinates form a valid rectangle
                    y1, y2 = sorted([point_dict[x_coords[i]][j], point_dict[x_coords[i]][k]])
                    width = x_coords[i + 1] - x_coords[i]
                    height = y2 - y1
                    area = width * height
                    min_area = min(min_area, area)
        
        return min_area if min_area!= float('inf') else 0   
        
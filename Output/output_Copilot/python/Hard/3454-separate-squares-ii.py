# You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.
# Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.
# Answers within 10-5 of the actual answer will be accepted.
# Note: Squares may overlap. Overlapping areas should be counted only once in this version.
# Example 1:
# Input: squares = [[0,0,1],[2,2,1]]
# Output: 1.00000
# Explanation:
# Any horizontal line between y = 1 and y = 2 results in an equal split, with 1 square unit above and 1 square unit below. The minimum y-value is 1.
# Example 2:
# Input: squares = [[0,0,2],[1,1,1]]
# Output: 1.00000
# Explanation:
# Since the blue square overlaps with the red square, it will not be counted again. Thus, the line y = 1 splits the squares into two equal parts.
# Constraints:
# 1 <= squares.length <= 5 * 104
# squares[i] = [xi, yi, li]
# squares[i].length == 3
# 0 <= xi, yi <= 109
# 1 <= li <= 109
# The total area of all the squares will not exceed 1015.

class Solution(object):
    def separateSquares(self, squares):
        """
        :type squares: List[List[int]]
        :rtype: float
        """
        from bisect import bisect_left, bisect_right
        
        # Calculate the total area of all squares
        total_area = sum(l * l for _, _, l in squares)
        
        # Sort squares by their bottom-left y-coordinate
        squares.sort(key=lambda x: x[1])
        
        # Prepare a list of y-coordinates and their corresponding areas
        y_coords = []
        areas = []
        
        current_area = 0
        for x, y, l in squares:
            current_area += l * l
            y_coords.append(y)
            areas.append(current_area)
        
        # Binary search to find the minimum y-coordinate that splits the area equally
        target_area = total_area / 2.0
        
        idx = bisect_left(areas, target_area)
        
        if idx == 0:
            return float(y_coords[0])
        
        if idx < len(areas) and areas[idx] == target_area:
            return float(y_coords[idx])
        
        # Interpolate between the two closest y-coordinates
        lower_y = y_coords[idx - 1]
        upper_y = y_coords[idx]
        
        lower_area = areas[idx - 1]
        upper_area = areas[idx]
        
        # Linear interpolation to find the exact y-coordinate
        ratio = (target_area - lower_area) / (upper_area - lower_area)
        
        return lower_y + ratio * (upper_y - lower_y)    
        
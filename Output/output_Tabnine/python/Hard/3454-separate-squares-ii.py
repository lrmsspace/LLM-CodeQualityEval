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
        # Sort the squares based on their x-coordinates
        squares.sort(key=lambda x: x[0])
        
        # Initialize variables
        min_y = float('inf')
        count = 0
        
        # Iterate through the sorted squares
        for i in range(len(squares)):
            x, y, side = squares[i]
            area_above = (y + side) * (y + side)
            area_below = (y - side) * (y - side)
            
            # Calculate the number of squares that can be placed above and below the current square
            while i + 1 < len(squares) and squares[i + 1][0] == x:
                i += 1
                area_above += (squares[i][1] + squares[i][2]) * (squares[i][1] + squares[i][2])
                area_below -= (squares[i][1] - squares[i][2]) * (squares[i][1] - squares[i][2])
            count += 1  
            # Update the minimum y-coordinate value
            min_y = min(min_y, y - side, y + side)  
            # Calculate the total area covered by squares above and below the current square
            total_area = area_above + area_below
            
            # Check if the total area is equal to the minimum y-coordinate value
            if abs(total_area - min_y * min_y) < 1e-5:
                return min_y
        return min_y / count
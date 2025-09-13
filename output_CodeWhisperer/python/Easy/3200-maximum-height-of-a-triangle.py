# You are given two integers red and blue representing the count of red and blue colored balls. You have to arrange these balls to form a triangle such that the 1st row will have 1 ball, the 2nd row will have 2 balls, the 3rd row will have 3 balls, and so on.
# All the balls in a particular row should be the same color, and adjacent rows should have different colors.
# Return the maximum height of the triangle that can be achieved.
# Example 1:
# Input: red = 2, blue = 4
# Output: 3
# Explanation:
# The only possible arrangement is shown above.
# Example 2:
# Input: red = 2, blue = 1
# Output: 2
# Explanation:
# The only possible arrangement is shown above.
# Example 3:
# Input: red = 1, blue = 1
# Output: 1
# Example 4:
# Input: red = 10, blue = 1
# Output: 2
# Explanation:
# The only possible arrangement is shown above.
# Constraints:
# 1 <= red, blue <= 100

import math
class Solution(object):
    def maxHeightOfTriangle(self, red, blue):
        """
        :type red: int
        :type blue: int
        :rtype: int
        """
        # 1. Calculate the total number of balls
        total = red + blue

        # 2. Calculate the maximum possible height of the triangle
        # The maximum height is the floor of the square root of (8 * total + 1)
        # This is because the triangle is formed by the sequence of numbers 1, 3, 6, 10, 15, ...
        # The formula for the sum of the first n natural numbers is n * (n + 1) / 2
        # So, the sum of the sequence up to the maximum height is (8 * total + 1) / 2
        # We use the floor function to get the integer part of this value
        return int((math.sqrt(8 * total + 1) - 1) / 2)        
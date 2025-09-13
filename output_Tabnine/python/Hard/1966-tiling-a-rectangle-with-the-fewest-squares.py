#https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/
#Given a rectangle of size n x m, return the minimum number of integer-sided squares that tile the rectangle.
# 
#Example 1:
#Input: n = 2, m = 3
#Output: 3
#Explanation: 3 squares are necessary to cover the rectangle.
#2 (squares of 1x1)
#1 (square of 2x2)
#Example 2:
#Input: n = 5, m = 8
#Output: 5
#Example 3:
#Input: n = 11, m = 13
#Output: 6
# 
#Constraints:
#	1 <= n, m <= 13
class Solution(object):
    def tilingRectangle(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        # Initialize a list to store the number of squares for each size
        squares = [0] * (n * m + 1)
        
        # Initialize the minimum number of squares to cover the entire rectangle
        min_squares = n * m
        
        # Iterate from the smallest possible square size to the maximum possible square size
        for size in range(1, int(n ** 0.5) + 1):
            # Calculate the number of squares needed for each size
            for i in range(n // size):
                for j in range(m // size):
                    # Update the minimum number of squares
                    min_squares = min(min_squares, squares[n - i * size - 1] + squares[m - j * size - 1] + size * 2)
            
            # Update the number of squares for each size
            for i in range(n // size):
                for j in range(m // size):
                    squares[i * size + j * size + size * 2] += 1
        
        return min_squares
        
# You are given two strings, coordinate1 and coordinate2, representing the coordinates of a square on an 8 x 8 chessboard.
# Below is the chessboard for reference.
# Return true if these two squares have the same color and false otherwise.
# The coordinate will always represent a valid chessboard square. The coordinate will always have the letter first (indicating its column), and the number second (indicating its row).
# Example 1:
# Input: coordinate1 = "a1", coordinate2 = "c3"
# Output: true
# Explanation:
# Both squares are black.
# Example 2:
# Input: coordinate1 = "a1", coordinate2 = "h3"
# Output: false
# Explanation:
# Square "a1" is black and "h3" is white.
# Constraints:
# coordinate1.length == coordinate2.length == 2
# 'a' <= coordinate1[0], coordinate2[0] <= 'h'
# '1' <= coordinate1[1], coordinate2[1] <= '8'

class Solution(object):
    def checkTwoChessboards(self, coordinate1, coordinate2):
        """
        :type coordinate1: str
        :type coordinate2: str
        :rtype: bool
        """
        # Initialize a list to store the color of each square
        board1 = [0] * 64
        board2 = [0] * 64
        
        # Fill the board with the color of each square
        for i in range(8):
            for j in range(8):
                board1[i * 8 + j] = (i + j) % 2
                board2[i * 8 + j] = (i + 7 - j) % 2
        
        # Convert the coordinates to indices
        index1 = 8 * (ord(coordinate1[0]) - ord('a')) + int(coordinate1[1]) - 1
        index2 = 8 * (ord(coordinate2[0]) - ord('a')) + int(coordinate2[1]) - 1
        
        # Check if the colors of the squares at the given indices are the same
        return board1 == board2[index1:index2+1] or board1 == board2[index2:index1+1]
        
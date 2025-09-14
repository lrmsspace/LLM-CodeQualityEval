#https://leetcode.com/problems/alphabet-board-path/
#On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].
#Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below.
#We may make the following moves:
#	'U' moves our position up one row, if the position exists on the board;
#	'D' moves our position down one row, if the position exists on the board;
#	'L' moves our position left one column, if the position exists on the board;
#	'R' moves our position right one column, if the position exists on the board;
#	'!' adds the character board[r][c] at our current position (r, c) to the answer.
#(Here, the only positions that exist on the board are positions with letters on them.)
#Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so.
# 
#Example 1:
#Input: target = "leet"
#Output: "DDR!UURRR!!DDD!"
#Example 2:
#Input: target = "code"
#Output: "RR!DDRR!UUL!R!"
# 
#Constraints:
#	1 <= target.length <= 100
#	target consists only of English lowercase letters.
class Solution(object):
    def alphabetBoardPath(self, target):
        """
        :type target: str
        :rtype: str
        """
        # 26个字母的坐标位置
        pos = {chr(i + ord('a')): (i // 5, i % 5) for i in range(26)}
        x, y = 0, 0 
        path = []
        for char in target:
            new_x, new_y = pos[char]
            # 计算横向和纵向的移动
            if new_x < x:
                path.append('U' * (x - new_x))
            if new_y < y:
                path.append('L' * (y - new_y))
            if new_x > x:
                path.append('D' * (new_x - x))
            if new_y > y:
                path.append('R' * (new_y - y))
            path.append('!')
            x, y = new_x, new_y
        return ''.join(path)
#         # 1. 直接计算坐标       
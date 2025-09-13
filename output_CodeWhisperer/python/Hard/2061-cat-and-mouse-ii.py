#https://leetcode.com/problems/cat-and-mouse-ii/
#A game is played by a cat and a mouse named Cat and Mouse.
#The environment is represented by a grid of size rows x cols, where each element is a wall, floor, player (Cat, Mouse), or food.
#	Players are represented by the characters 'C'(Cat),'M'(Mouse).
#	Floors are represented by the character '.' and can be walked on.
#	Walls are represented by the character '#' and cannot be walked on.
#	Food is represented by the character 'F' and can be walked on.
#	There is only one of each character 'C', 'M', and 'F' in grid.
#Mouse and Cat play according to the following rules:
#	Mouse moves first, then they take turns to move.
#	During each turn, Cat and Mouse can jump in one of the four directions (left, right, up, down). They cannot jump over the wall nor outside of the grid.
#	catJump, mouseJump are the maximum lengths Cat and Mouse can jump at a time, respectively. Cat and Mouse can jump less than the maximum length.
#	Staying in the same position is allowed.
#	Mouse can jump over Cat.
#The game can end in 4 ways:
#	If Cat occupies the same position as Mouse, Cat wins.
#	If Cat reaches the food first, Cat wins.
#	If Mouse reaches the food first, Mouse wins.
#	If Mouse cannot get to the food within 1000 turns, Cat wins.
#Given a rows x cols matrix grid and two integers catJump and mouseJump, return true if Mouse can win the game if both Cat and Mouse play optimally, otherwise return false.
# 
#Example 1:
#Input: grid = ["####F","#C...","M...."], catJump = 1, mouseJump = 2
#Output: true
#Explanation: Cat cannot catch Mouse on its turn nor can it get the food before Mouse.
#Example 2:
#Input: grid = ["M.C...F"], catJump = 1, mouseJump = 4
#Output: true
#Example 3:
#Input: grid = ["M.C...F"], catJump = 1, mouseJump = 3
#Output: false
# 
#Constraints:
#	rows == grid.length
#	cols = grid[i].length
#	1 <= rows, cols <= 8
#	grid[i][j] consist only of characters 'C', 'M', 'F', '.', and '#'.
#	There is only one of each character 'C', 'M', and 'F' in grid.
#	1 <= catJump, mouseJump <= 8
class Solution(object):
    def canMouseWin(self, grid, catJump, mouseJump):
        """
        :type grid: List[str]
        :type catJump: int
        :type mouseJump: int
        :rtype: bool
        """
        m, n = len(grid), len(grid[0])
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        def getPos():
            for i in range(m):
                for j in range(n):
                    if grid[i][j] == 'M': mouse = (i, j)
                    elif grid[i][j] == 'C': cat = (i, j)
                    elif grid[i][j] == 'F': food = (i, j)
            return mouse, cat, food
        mouse, cat, food = getPos()
        def dfs(mouse, cat, turn):
            if (mouse, cat, turn) in memo: return memo[mouse, cat, turn]
            if turn == 2:
                if cat == food: return False
                else: return True
            if mouse == cat or mouse == food: return False
            if turn == 0:
                for dx, dy in dirs:
                    for i in range(mouseJump + 1):
                        x, y = mouse[0] + dx * i, mouse[1] + dy * i
                        if 0 <= x < m and 0 <= y < n and grid[x][y] != '#':
                            if dfs((x, y), cat, 1): return True
                        else: break
                return False
            else:
                for dx, dy in dirs:
                    for i in range(catJump + 1):
                        x, y = cat[0] + dx * i, cat[1] + dy * i
                        if 0 <= x < m and 0 <= y < n and grid[x][y] != '#':
                            if not dfs(mouse, (x, y), 0) or (x, y) == food: return False
                        else: break
                return True
        memo = {}
        return dfs(mouse, cat, 0)
        
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
        rows, cols = len(grid), len(grid[0])
        mouse_pos = (0, 0)
        cat_pos = (0, 0)
        food_pos = (0, 0)
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 'M':
                    mouse_pos = (i, j)
                elif grid[i][j] == 'C':
                    cat_pos = (i, j)
                elif grid[i][j] == 'F':
                    food_pos = (i, j)
        
        # use a tuple to represent the state
        # the first two elements are the mouse position
        # the second two elements are the cat position
        # the last three elements are the remaining steps, cat jump and mouse jump
        # the last element is the result of the game
        queue = [(mouse_pos, cat_pos, 1000, catJump, mouseJump, True)]
        visited = set()
        while queue:
            (m_x, m_y), (c_x, c_y), steps, c_jump, m_jump, result = queue.pop(0)
            if (m_x, m_y, c_x, c_y, steps, c_jump, m_jump) in visited:
                continue
            visited.add((m_x, m_y, c_x, c_y, steps, c_jump, m_jump))
            if (m_x, m_y) == food_pos:
                return result
            if (c_x, c_y) == food_pos:
                return not result
            if (m_x, m_y) == (c_x, c_y):
                return not result
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                new_m_x, new_m_y = m_x + dx * m_jump, m_y + dy * m_jump
                if 0 <= new_m_x < rows and 0 <= new_m_y < cols and grid[new_m_x][new_m_y] != '#':
                    queue.append(((new_m_x, new_m_y), (c_x, c_y), steps - 1, c_jump, m_jump, result))
                new_c_x, new_c_y = c_x + dx * c_jump, c_y + dy * c_jump
                if 0 <= new_c_x < rows and 0 <= new_c_y < cols and grid[new_c_x][new_c_y] != '#':
                    queue.append(((m_x, m_y), (new_c_x, new_c_y), steps - 1, c_jump, m_jump, not result))

        return False
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
        cat, mouse, food = None, None, None
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 'C':
                    cat = (i, j)
                elif grid[i][j] == 'M':
                    mouse = (i, j)
                elif grid[i][j] == 'F':
                    food = (i, j)

        def canReach(start, end, jump):
            visited = set()
            queue = [start]
            while queue:
                x, y = queue.pop(0)
                if (x, y) == end:
                    return True
                if (x, y) in visited:
                    continue
                visited.add((x, y))
                for dx in range(-jump, jump + 1):
                    for dy in range(-jump, jump + 1):
                        if abs(dx) + abs(dy) <= jump and 0 <= x + dx < rows and 0 <= y + dy < cols and grid[x + dx][y + dy] != '#':
                            queue.append((x + dx, y + dy))
            return False

        def dfs(cat_pos, mouse_pos, turn):
            if cat_pos == mouse_pos:
                return False
            if turn > 1000:
                return False
            if turn % 2 == 0:     # Cat's turn
                for dx in range(-catJump, catJump + 1):
                    for dy in range(-catJump, catJump + 1):
                        if abs(dx) + abs(dy) <= catJump and 0 <= cat_pos[0] + dx < rows and 0 <= cat_pos[1] + dy < cols and grid[cat_pos[0] + dx][cat_pos[1] + dy] != '#':
                            new_cat_pos = (cat_pos[0] + dx, cat_pos[1] + dy)
                            if not dfs(new_cat_pos, mouse_pos, turn + 1):
                                return True
            else:                # Mouse's turn
                for dx in range(-mouseJump, mouseJump + 1):
                    for dy in range(-mouseJump, mouseJump + 1):
                        if abs(dx) + abs(dy) <= mouseJump and 0 <= mouse_pos[0] + dx < rows and 0 <= mouse_pos[1] + dy < cols and grid[mouse_pos[0] + dx][mouse_pos[1] + dy] != '#':
                            new_mouse_pos = (mouse_pos[0] + dx, mouse_pos[1] + dy)
                            if new_mouse_pos == food or not dfs(cat_pos, new_mouse_pos, turn + 1):
                                return True
            return False    

        return dfs(cat, mouse, 0) and canReach(mouse, food, mouseJump) and not canReach(cat, food, catJump)
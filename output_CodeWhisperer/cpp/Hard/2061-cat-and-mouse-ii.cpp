/**https://leetcode.com/problems/cat-and-mouse-ii/ */
//A game is played by a cat and a mouse named Cat and Mouse.
//The environment is represented by a grid of size rows x cols, where each element is a wall, floor, player (Cat, Mouse), or food.
//	Players are represented by the characters 'C'(Cat),'M'(Mouse).
//	Floors are represented by the character '.' and can be walked on.
//	Walls are represented by the character '#' and cannot be walked on.
//	Food is represented by the character 'F' and can be walked on.
//	There is only one of each character 'C', 'M', and 'F' in grid.
//Mouse and Cat play according to the following rules:
//	Mouse moves first, then they take turns to move.
//	During each turn, Cat and Mouse can jump in one of the four directions (left, right, up, down). They cannot jump over the wall nor outside of the grid.
//	catJump, mouseJump are the maximum lengths Cat and Mouse can jump at a time, respectively. Cat and Mouse can jump less than the maximum length.
//	Staying in the same position is allowed.
//	Mouse can jump over Cat.
//The game can end in 4 ways:
//	If Cat occupies the same position as Mouse, Cat wins.
//	If Cat reaches the food first, Cat wins.
//	If Mouse reaches the food first, Mouse wins.
//	If Mouse cannot get to the food within 1000 turns, Cat wins.
//Given a rows x cols matrix grid and two integers catJump and mouseJump, return true if Mouse can win the game if both Cat and Mouse play optimally, otherwise return false.
// 
//Example 1:
//Input: grid = ["####F","#C...","M...."], catJump = 1, mouseJump = 2
//Output: true
//Explanation: Cat cannot catch Mouse on its turn nor can it get the food before Mouse.
//Example 2:
//Input: grid = ["M.C...F"], catJump = 1, mouseJump = 4
//Output: true
//Example 3:
//Input: grid = ["M.C...F"], catJump = 1, mouseJump = 3
//Output: false
// 
//Constraints:
//	rows == grid.length
//	cols = grid[i].length
//	1 <= rows, cols <= 8
//	grid[i][j] consist only of characters 'C', 'M', 'F', '.', and '#'.
//	There is only one of each character 'C', 'M', and 'F' in grid.
//	1 <= catJump, mouseJump <= 8
class Solution {
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        int rows = grid.size(), cols = grid[0].size();
        int startMouse = -1, startCat = -1, food = -1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                char c = grid[i][j];
                if (c == 'M') startMouse = i * cols + j;
                else if (c == 'C') startCat = i * cols + j;
                else if (c == 'F') food = i * cols + j;
            }
        }
        vector<int> directions = {-1, 0, 1, 0, -1};
        vector<vector<vector<vector<bool>>>> dp(rows, vector<vector<vector<bool>>>(cols, vector<vector<bool>>(rows, vector<bool>(cols, false))));
        
        function<bool(int, int, int, int, int)> dfs = [&](int mouse, int cat, int turn, int lastMouse, int lastCat) -> bool {
            if (mouse == cat) return false;
            if (mouse == food) return true;
            if (cat == food) return false;
            if (turn >= 1000) return false;
            if (dp[mouse][cat][lastMouse][lastCat]) return false;
            dp[mouse][cat][lastMouse][lastCat] = true;
            int mouseRow = mouse / cols, mouseCol = mouse % cols;
            int catRow = cat / cols, catCol = cat % cols;
            if (turn % 2 == 0) {
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j <= mouseJump; j++) {
                        int newMouseRow = mouseRow + directions[i] * j;
                        int newMouseCol = mouseCol + directions[i + 1] * j;
                        if (newMouseRow < 0 || newMouseRow >= rows || newMouseCol < 0 || newMouseCol >= cols || grid[newMouseRow][newMouseCol] == '#') break;
                        if (dfs(newMouseRow * cols + newMouseCol, cat, turn + 1, mouse, cat) == false) return true;
                    }
                }
            } else {
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j <= catJump; j++) {
                        int newCatRow = catRow + directions[i] * j;
                        int newCatCol = catCol + directions[i + 1] * j;
                        if (newCatRow < 0 || newCatRow >= rows || newCatCol < 0 || newCatCol >= cols || grid[newCatRow][newCatCol] == '#') break;
                        if (dfs(mouse, newCatRow * cols + newCatCol, turn + 1, mouse, cat) == false) return true;
                    }
                }
            }
            return false;
        };
        return dfs(startMouse, startCat, 0, startMouse, startCat);
    }
};
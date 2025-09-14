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
        int m = grid.size(), n = grid[0].size();

        int M = 0, C = 0, F = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                switch (grid[i][j])
                {
                case 'M':
                    M = i * n + j;
                    break;
                case 'C':
                    C = i * n + j;
                    break;
                case 'F':
                    F = i * n + j;
                    break;
                }
        int dirs[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
        queue<int> q;
        q.push(M);
        q.push(C);
        q.push(F);
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(m * n, false)));
        vis[M / n][M % n][C] = true;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            int y = q.front();
            q.pop();
            int z = q.front();
            q.pop();
            if (x == z)
                return false;
            for (int i = 0; i < 4; ++i)
                for (int j = 1; j <= mouseJump; ++j)
                {
                    int nx = x + j * dirs[i][0];
                    int ny = y + j * dirs[i][1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#')
                        break;
                    if (vis[nx][ny][z])
                        continue;
                    vis[nx][ny][z] = true;
                    q.push(nx * n + ny);
                    q.push(y);
                    q.push(z);
                }
        }
        q.push(F);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
                for (int j = 1; j <= catJump; ++j)
                {
                    int nx = x + j * dirs[i][0];
                    int ny = x + j * dirs[i][1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#')
                        break;
                    if (vis[nx][ny][x])
                        continue;
                   vis[nx][ny][x] = true;
                }
        }
        return vis[M / n][M % n][F];
    }
};
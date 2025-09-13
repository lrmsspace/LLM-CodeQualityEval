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
/**
 * @param {string[]} grid
 * @param {number} catJump
 * @param {number} mouseJump
 * @return {boolean}
 */
var canMouseWin = function(grid, catJump, mouseJump) {
    const m = grid.length, n = grid[0].length;
    const dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    const M = 'M', C = 'C', H = 'H';
    const start = [];
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === M) {
                start.push([i, j]);
            }
        }
    }
    const keys = new Set();
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                keys.add(grid[i][j]);
            }
        }
    }
    const dirs = [[0, 1], [0, -1], [1, 0], [-1, 0]];

        const q = [];
        for (const [i, j] of start) {
            const key = grid[i][j];
            if (key >= 'a' && key <= 'z') {
                keys.delete(key);
            }
            q.push([i, j, 0, key]);
        }
        while (q.length) {
            const [i, j, step, key] = q.shift();
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] === '#') {
                continue;
            }
            const newKey = key + grid[i][j];
            if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                if (!keys.has(grid[i][j])) {
                    continue;
                }
                keys.delete(grid[i][j]);
            }
            if (grid[i][j] >= 'A' && grid[i][j] <= 'Z' && !key.includes(grid[i][j]))
                continue;
        }
        if (newKey === key) {
            continue;
        }
        if (newKey === end) {
            return step + 1;
        }
        if (visited.has(newKey)) {
            continue;
        }
        visited.add(newKey);
        queue.push([newKey, step + 1]);
        for (let [di, dj] of dirs) {
            let ni = i + di;
            let nj = j + dj;
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
                continue;
            }
            queue.push([newKey, step + 1]);
        }
        return false;
};
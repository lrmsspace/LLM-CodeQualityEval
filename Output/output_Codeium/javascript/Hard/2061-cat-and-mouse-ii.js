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
    const rows = grid.length;
    const cols = grid[0].length;
    const directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    const memo = new Map();
    const catMove = (x, y, mx, my, jumps) => {
        if (jumps === 0) return [x, y];
        for (const [dx, dy] of directions) {
            const nx = x + dx * Math.min(jumps, catJump);
            const ny = y + dy * Math.min(jumps, catJump);
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] !== '#') {
                return [nx, ny];
            }
        }
        return [x, y];
    };
    const dfs = (mx, my, cx, cy, jumps) => {
        const key = `${mx},${my},${cx},${cy},${jumps}`;
        if (memo.has(key)) return memo.get(key);
        if (mx === cx && my === cy) return false;
        if (grid[mx][my] === 'F') return true;
        let res = false;
        for (const [dx, dy] of directions) {
            const nx = mx + dx * Math.min(jumps, mouseJump);
            const ny = my + dy * Math.min(jumps, mouseJump);
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] !== '#') {
                const [cx2, cy2] = catMove(cx, cy, nx, ny, jumps);
                res = res || !dfs(nx, ny, cx2, cy2, jumps - 1);
            }
        }
        memo.set(key, res);
        return res;
    };

    let mx = -1, my = -1, cx = -1, cy = -1;
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (grid[i][j] === 'M') [mx, my] = [i, j];
            if (grid[i][j] === 'C') [cx, cy] = [i, j];
        }
    }
    return dfs(mx, my, cx, cy, 1000);
};
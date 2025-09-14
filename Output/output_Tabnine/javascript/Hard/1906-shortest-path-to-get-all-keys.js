/**https://leetcode.com/problems/shortest-path-to-get-all-keys/ */
//You are given an m x n grid grid where:
//	'.' is an empty cell.
//	'#' is a wall.
//	'@' is the starting point.
//	Lowercase letters represent keys.
//	Uppercase letters represent locks.
//You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.
//If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.
//For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.
//Return the lowest number of moves to acquire all keys. If it is impossible, return -1.
// 
//Example 1:
//Input: grid = ["@.a..","###.#","b.A.B"]
//Output: 8
//Explanation: Note that the goal is to obtain all the keys not to open all the locks.
//Example 2:
//Input: grid = ["@..aA","..B#.","....b"]
//Output: 6
//Example 3:
//Input: grid = ["@Aa"]
//Output: -1
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 30
//	grid[i][j] is either an English letter, '.', '#', or '@'. 
//	There is exactly one '@' in the grid.
//	The number of keys in the grid is in the range [1, 6].
//	Each key in the grid is unique.
//	Each key in the grid has a matching lock.
/**
 * @param {string[]} grid
 * @return {number}
 */
var shortestPathAllKeys = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    const keys = [];
    const doors = {};
    let startX = -1, startY = -1;
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === '@') {
                startX = i;
                startY = j;
            } else if (grid[i][j].match(/[a-z]/)) {
                keys.push(grid[i][j]);
            } else if (grid[i][j].match(/[A-Z]/)) {
                doors[grid[i][j]] = [i, j];
            }
        }
    }
    
    const directions = [[0, 1], [0, -1], [1, 0], [-1, 0]];
    const visited = new Set();
    const queue = [[startX, startY, 0, '']];
    
    while (queue.length) {
        const [x, y, moves, keys] = queue.shift();
        
        if (keys.length === keys.length) {
            return moves;
        }
        
        if (visited.has(`${x},${y},${keys}`)) {
            continue;
        }
        
        visited.add(`${x},${y},${keys}`);
        
        for (const [dx, dy] of directions) {
            const nx = x + dx;
            const ny = y + dy;
            
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] === '#') {
                continue;
            }
            
            let newKeys = keys;
            let newDoor = null;
            
            if (grid[nx][ny].match(/[a-z]/)) {
                newKeys = keys.includes(grid[nx][ny])? keys : [...keys, grid[nx][ny]];
            } else if (grid[nx][ny].match(/[A-Z]/)) {
                newDoor = [nx, ny];
            }
    
            if (newDoor && doors[grid[nx][ny]] && newKeys.includes(grid[doors[grid[nx][ny]][0]][grid[doors[grid[nx][ny]][1]].toLowerCase()])) {
                queue.push([nx, ny, moves + 1, newKeys]);
            } else {
                queue.push([nx, ny, moves + 1, newKeys]);
            }
            
    
            if (newKeys.length === keys.length) {
                return moves + 1;
            }
        }
        
        grid[x][y] = grid[x][y].replace(/[a-z]/, '.');
    
        if (newDoor) {
            grid[doors[grid[x][y]][0]][doors[grid[x][y]][1]] = grid[doors[grid[x][y]][0]][doors[grid[x][y]][1]].toUpperCase();
        }
    }
    
    return -1;
    
};
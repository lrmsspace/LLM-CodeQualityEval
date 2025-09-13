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
    const m = grid.length, n = grid[0].length;
    let startX, startY, keys = 0;
    const directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    const queue = [];
    const visited = new Set();

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === '@') {
                startX = i;
                startY = j;
            } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                keys++;
            }
        }
    }

    queue.push([startX, startY, 0, 0]); // x, y, keys collected, steps
    visited.add(`${startX},${startY},0`);

    while (queue.length) {
        const [x, y, collectedKeys, steps] = queue.shift();
        if (collectedKeys === (1 << keys) - 1) return steps;

        for (const [dx, dy] of directions) {
            const newX = x + dx;
            const newY = y + dy;

            if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] === '#') continue;

            let newCollectedKeys = collectedKeys;
            if (grid[newX][newY] >= 'a' && grid[newX][newY] <= 'f') {
                newCollectedKeys |= (1 << (grid[newX][newY].charCodeAt(0) - 'a'.charCodeAt(0)));
            } else if (grid[newX][newY] >= 'A' && grid[newX][newY] <= 'F') {
                if (!(collectedKeys & (1 << (grid[newX][newY].charCodeAt(0) - 'A'.charCodeAt(0))))) continue;
            }

            if (!visited.has(`${newX},${newY},${newCollectedKeys}`)) {
                visited.add(`${newX},${newY},${newCollectedKeys}`);
                queue.push([newX, newY, newCollectedKeys, steps + 1]);
            }  
        }
    }
    return -1; // If all keys cannot be collected  
};
/*
 You are given four integers sx, sy, fx, fy, and a non-negative integer t.
 In an infinite 2D grid, you start at the cell (sx, sy). Each second, you must move to any of its adjacent cells.
 Return true if you can reach cell (fx, fy) after exactly t seconds, or false otherwise.
 A cell's adjacent cells are the 8 cells around it that share at least one corner with it. You can visit the same cell several times.
 Example 1:
 Input: sx = 2, sy = 4, fx = 7, fy = 7, t = 6
 Output: true
 Explanation: Starting at cell (2, 4), we can reach cell (7, 7) in exactly 6 seconds by going through the cells depicted in the picture above. 
 Example 2:
 Input: sx = 3, sy = 1, fx = 7, fy = 3, t = 3
 Output: false
 Explanation: Starting at cell (3, 1), it takes at least 4 seconds to reach cell (7, 3) by going through the cells depicted in the picture above. Hence, we cannot reach cell (7, 3) at the third second.
 Constraints:
 1 <= sx, sy, fx, fy <= 109
 0 <= t <= 109
*/

/**
 * @param {number} sx
 * @param {number} sy
 * @param {number} fx
 * @param {number} fy
 * @param {number} t
 * @return {boolean}
 */
var isReachableAtTime = function(sx, sy, fx, fy, t) {
    // BFS to find the shortest path to reach (fx, fy) within time t
    const dx = [1, 0, -1, 0];
    const dy = [0, 1, 0, -1];
    const queue = [[sx, sy, 0]];
    const visited = new Set();

    while (queue.length > 0) {
        const [x, y, time] = queue.shift(); 
        if (x === fx && y === fy) {
            return true;
        }
        if (time > t) {
            continue;
        }
        for (let i = 0; i < 4; i++) {
            const nx = x + dx[i];
            const ny = y + dy[i];
            if (nx >= 0 && nx <= 10**9 && ny >= 0 && ny <= 10**9 &&!visited.has(`${nx},${ny}`)) {
                visited.add(`${nx},${ny}`);
                queue.push([nx, ny, time + 1]);
            }
        }
        // Add other adjacent cells to the queue
        queue.push([x + 1, y, time + 1]);
        queue.push([x - 1, y, time + 1]);
        queue.push([x, y + 1, time + 1]);
        queue.push([x, y - 1, time + 1]);
    }
    return false;
    
};
/**https://leetcode.com/problems/escape-the-spreading-fire/ */
//You are given a 0-indexed 2D integer array grid of size m x n which represents a field. Each cell has one of three values:
//	0 represents grass,
//	1 represents fire,
//	2 represents a wall that you and fire cannot pass through.
//You are situated in the top-left cell, (0, 0), and you want to travel to the safehouse at the bottom-right cell, (m - 1, n - 1). Every minute, you may move to an adjacent grass cell. After your move, every fire cell will spread to all adjacent cells that are not walls.
//Return the maximum number of minutes that you can stay in your initial position before moving while still safely reaching the safehouse. If this is impossible, return -1. If you can always reach the safehouse regardless of the minutes stayed, return 109.
//Note that even if the fire spreads to the safehouse immediately after you have reached it, it will be counted as safely reaching the safehouse.
//A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
// 
//Example 1:
//Input: grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
//Output: 3
//Explanation: The figure above shows the scenario where you stay in the initial position for 3 minutes.
//You will still be able to safely reach the safehouse.
//Staying for more than 3 minutes will not allow you to safely reach the safehouse.
//Example 2:
//Input: grid = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
//Output: -1
//Explanation: The figure above shows the scenario where you immediately move towards the safehouse.
//Fire will spread to any cell you move towards and it is impossible to safely reach the safehouse.
//Thus, -1 is returned.
//Example 3:
//Input: grid = [[0,0,0],[2,2,0],[1,2,0]]
//Output: 1000000000
//Explanation: The figure above shows the initial grid.
//Notice that the fire is contained by walls and you will always be able to safely reach the safehouse.
//Thus, 109 is returned.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	2 <= m, n <= 300
//	4 <= m * n <= 2 * 104
//	grid[i][j] is either 0, 1, or 2.
//	grid[0][0] == grid[m - 1][n - 1] == 0
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maximumMinutes = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    const dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    
    // Function to calculate fire spread time to each cell
    function getFireTime() {
        const fireTime = Array(m).fill().map(() => Array(n).fill(Infinity));
        const queue = [];
        
        // Find initial fire positions
        for (let i = 0; i < m; i++) {
            for (let j = 0; j < n; j++) {
                if (grid[i][j] === 1) {
                    queue.push([i, j, 0]);
                    fireTime[i][j] = 0;
                }
            }
        }
        
        // BFS for fire spread
        while (queue.length) {
            const [x, y, time] = queue.shift();
            
            for (const [dx, dy] of dirs) {
                const nx = x + dx;
                const ny = y + dy;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    grid[nx][ny] === 0 && fireTime[nx][ny] === Infinity) {
                    fireTime[nx][ny] = time + 1;
                    queue.push([nx, ny, time + 1]);
                }
            }
        }
        
        return fireTime;
    }
    
    // Function to check if escape is possible with given waiting time
    function canEscape(waitTime, fireTime) {
        if (waitTime > fireTime[0][0] && fireTime[0][0] !== Infinity) return false;
        
        const visited = Array(m).fill().map(() => Array(n).fill(false));
        const queue = [[0, 0, waitTime]];
        visited[0][0] = true;
        
        while (queue.length) {
            const [x, y, time] = queue.shift();
            
            for (const [dx, dy] of dirs) {
                const nx = x + dx;
                const ny = y + dy;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    grid[nx][ny] === 0 && !visited[nx][ny]) {
                    
                    // Reached the target
                    if (nx === m-1 && ny === n-1) {
                        return time + 1 <= fireTime[nx][ny] || fireTime[nx][ny] === Infinity;
                    }
                    
                    // Continue if we can reach this cell before fire
                    if (time + 1 < fireTime[nx][ny]) {
                        visited[nx][ny] = true;
                        queue.push([nx, ny, time + 1]);
                    }
                }
            }
        }
        
        return false;
    }
    
    // Calculate fire spread time to each cell
    const fireTime = getFireTime();
    
    // Binary search for maximum waiting time
    let left = 0;
    let right = 1e9;
    let result = -1;
    
    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        
        if (canEscape(mid, fireTime)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
};
    
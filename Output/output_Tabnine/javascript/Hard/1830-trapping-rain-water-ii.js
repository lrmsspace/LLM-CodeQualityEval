/**https://leetcode.com/problems/trapping-rain-water-ii/ */
//Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.
// 
//Example 1:
//Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
//Output: 4
//Explanation: After the rain, water is trapped between the blocks.
//We have two small ponds 1 and 3 units trapped.
//The total volume of water trapped is 4.
//Example 2:
//Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
//Output: 10
// 
//Constraints:
//	m == heightMap.length
//	n == heightMap[i].length
//	1 <= m, n <= 200
//	0 <= heightMap[i][j] <= 2 * 104
/**
 * @param {number[][]} heightMap
 * @return {number}
 */
var trapRainWater = function(heightMap) {
    const m = heightMap.length;
    const n = heightMap[0].length;
    const directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    const visited = Array.from({ length: m }, () => Array.from({ length: n }, () => false));
    const pq = [];
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 || i === m - 1 || j === 0 || j === n - 1) {
                heapq.push([heightMap[i][j], i, j]);
                visited[i][j] = true;
            }
        }
    }
    
    while (pq.length > 0) {
        const [height, i, j] = heapq.pop();
        
        for (const [di, dj] of directions) {
            const ni = i + di;
            const nj = j + dj;
            
            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&!visited[ni][nj]) {
                visited[ni][nj] = true;
                heapq.push([Math.max(height, heightMap[ni][nj]), ni, nj]);
            }
        }
    }
    
    let total = 0;
    
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            total += heightMap[i][j] - pq[i * n + j][0];
        }
    }
    
    return total;
    
};
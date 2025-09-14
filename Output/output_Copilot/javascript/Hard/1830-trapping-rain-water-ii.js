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
    const visited = Array.from({ length: m }, () => Array(n).fill(false));
    const minHeap = new MinHeap();
    let waterTrapped = 0;

    // Initialize the heap with the boundary cells
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 || i === m - 1 || j === 0 || j === n - 1) {
                minHeap.push([heightMap[i][j], i, j]);
                visited[i][j] = true;
            }
        }
    }

    // Directions for moving in the grid
    const directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];

    while (minHeap.size() > 0) {
        const [height, x, y] = minHeap.pop();
        for (const [dx, dy] of directions) {
            const nx = x + dx;
            const ny = y + dy;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                waterTrapped += Math.max(0, height - heightMap[nx][ny]);
                minHeap.push([Math.max(height, heightMap[nx][ny]), nx, ny]);
                visited[nx][ny] = true;
            }
        }
    }

    return waterTrapped;    
};
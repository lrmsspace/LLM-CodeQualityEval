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
    const m = heightMap.length, n = heightMap[0].length;
    const pq = [], res = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 || j === 0 || i === m - 1 || j === n - 1) {
                pq.push([heightMap[i][j], i, j]);
                heightMap[i][j] = -1;
            }
        }
    }
    const dir = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    while (pq.length > 0) {
        const [h, x, y] = pq.sort((a, b) => a[0] - b[0])[0];
        pq.shift();
        for (let d = 0; d < 4; d++) {
            const nx = x + dir[d][0], ny = y + dir[d][1];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || heightMap[nx][ny] === -1) continue;
            if (heightMap[nx][ny] < h) {
                res += h - heightMap[nx][ny];
                heightMap[nx][ny] = h;
            }
            pq.push([heightMap[nx][ny], nx, ny]);
        }
    }
    return res;
    
};
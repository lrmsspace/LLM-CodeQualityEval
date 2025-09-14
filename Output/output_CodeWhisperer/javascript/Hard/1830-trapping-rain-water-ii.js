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
    let m = heightMap.length;
    let n = heightMap[0].length;
    let heap = [];
    let visited = new Array(m).fill(0).map(() => new Array(n).fill(false));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                heap.push([heightMap[i][j], i, j]);
                visited[i][j] = true;
            }
        }
    }
    heap.sort((a, b) => a[0] - b[0]);
    let dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    let res = 0;
    while (heap.length > 0) {
        let [h, i, j] = heap.shift();
        for (let dir of dirs) {
            let x = i + dir[0];
            let y = j + dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                res += Math.max(0, h - heightMap[x][y]);
                heap.push([Math.max(h, heightMap[x][y]), x, y]);
                visited[x][y] = true;
            }
        }
    }
    return res;
};
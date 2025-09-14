/**https://leetcode.com/problems/cyclically-rotating-a-grid/ */
//You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.
//The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:
//A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:
//Return the matrix after applying k cyclic rotations to it.
// 
//Example 1:
//Input: grid = [[40,10],[30,20]], k = 1
//Output: [[10,20],[40,30]]
//Explanation: The figures above represent the grid at every state.
//Example 2:
//  
//Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
//Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
//Explanation: The figures above represent the grid at every state.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	2 <= m, n <= 50
//	Both m and n are even integers.
//	1 <= grid[i][j] <= 5000
//	1 <= k <= 109
/**

 * @param {number[][]} grid

 * @param {number} k

 * @return {number[][]}

 */

var rotateGrid = function(grid, k) {

    const m = grid.length;
    const n = grid[0].length;
    const layers = Math.min(m, n) / 2; // Number of layers in the grid

    for (let layer = 0; layer < layers; layer++) {
        const top = layer;
        const left = layer;
        const bottom = m - layer - 1;
        const right = n - layer - 1;

        // Calculate the number of elements in the current layer
        const numElements = 2 * (bottom - top + right - left);

        // Calculate the effective number of rotations needed
        const effectiveK = k % numElements;

        // Store the elements of the current layer in a temporary array
        const tempLayer = [];

        for (let i = left; i <= right; i++) {
            tempLayer.push(grid[top][i]); // Top row
        }
        for (let i = top + 1; i <= bottom; i++) {
            tempLayer.push(grid[i][right]); // Right column
        }
        for (let i = right - 1; i >= left; i--) {
            tempLayer.push(grid[bottom][i]); // Bottom row
        }
        for (let i = bottom - 1; i > top; i--) {
            tempLayer.push(grid[i][left]); // Left column
        }

        // Rotate the temporary array
        const rotatedLayer = [...tempLayer.slice(-effectiveK), ...tempLayer.slice(0, -effectiveK)];

        // Place the rotated elements back into the grid
        let index = 0;
        for (let i = left; i <= right; i++) {
            grid[top][i] = rotatedLayer[index++]; // Top row
        }
        for (let i = top + 1; i <= bottom; i++) {
            grid[i][right] = rotatedLayer[index++]; // Right column
        }
        for (let i = right - 1; i >= left; i--) {
            grid[bottom][i] = rotatedLayer[index++]; // Bottom row
        }
        for (let i = bottom - 1; i > top; i--) {
            grid[i][left] = rotatedLayer[index++]; // Left column
        }
    }

    return grid;
    
};
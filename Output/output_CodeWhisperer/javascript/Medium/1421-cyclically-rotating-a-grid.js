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

    let m = grid.length, n = grid[0].length;

    let rotate = function(arr, k) {

        let len = arr.length;

        k %= len;

        if (k === 0) return arr;

        let res = [];

        for (let i = 0; i < len; i++) {

            res[(i + k) % len] = arr[i];

        }

        return res;

    };

    for (let i = 0; i < Math.min(m, n) / 2; i++) {

        let arr = [];

        for (let j = i; j < n - i; j++) arr.push(grid[i][j]);

        for (let j = i + 1; j < m - i; j++) arr.push(grid[j][n - i - 1]);

        for (let j = n - i - 2; j >= i; j--) arr.push(grid[m - i - 1][j]);

        for (let j = m - i - 2; j > i; j--) arr.push(grid[j][i]);

        arr = rotate(arr, k);

        let idx = 0;

        for (let j = i; j < n - i; j++) grid[i][j] = arr[idx++];

        for (let j = i + 1; j < m - i; j++) grid[j][n - i - 1] = arr[idx++];

        for (let j = n - i - 2; j >= i; j--) grid[m - i - 1][j] = arr[idx++];

        for (let j = m - i - 2; j > i; j--) grid[j][i] = arr[idx++];

    }

    return grid;

};
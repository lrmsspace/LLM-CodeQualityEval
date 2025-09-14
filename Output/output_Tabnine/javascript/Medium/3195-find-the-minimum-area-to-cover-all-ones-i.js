/*
 You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.
 Return the minimum possible area of the rectangle.
 Example 1:
 Input: grid = [[0,1,0],[1,0,1]]
 Output: 6
 Explanation:
 The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.
 Example 2:
 Input: grid = [[1,0],[0,0]]
 Output: 1
 Explanation:
 The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.
 Constraints:
 1 <= grid.length, grid[i].length <= 1000
 grid[i][j] is either 0 or 1.
 The input is generated such that there is at least one 1 in grid.
*/

/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumArea = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    let minArea = Infinity;
    
    // Initialize a 2D array dp of size m x n to store the minimum area for each cell
    const dp = Array.from({length: m}, () => Array(n).fill(Infinity));
    
    // Initialize the dp array with the values from the given grid
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            dp[i][j] = grid[i][j] === 1? 0 : Infinity;
        }
    }
    // Fill the dp array using a dynamic programming approach
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            if (grid[i][j] === 1) {
                dp[i][j] = Math.min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
                minArea = Math.min(minArea, dp[i][j] * dp[i][j]);
            }
        }
    }
    
    return minArea; 
    
};
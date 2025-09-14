/**https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/ */
//You are given a 2D integer array grid of size m x n, where each cell contains a positive integer.
//A cornered path is defined as a set of adjacent cells with at most one turn. More specifically, the path should exclusively move either horizontally or vertically up to the turn (if there is one), without returning to a previously visited cell. After the turn, the path will then move exclusively in the alternate direction: move vertically if it moved horizontally, and vice versa, also without returning to a previously visited cell.
//The product of a path is defined as the product of all the values in the path.
//Return the maximum number of trailing zeros in the product of a cornered path found in grid.
//Note:
//	Horizontal movement means moving in either the left or right direction.
//	Vertical movement means moving in either the up or down direction.
// 
//Example 1:
//Input: grid = [[23,17,15,3,20],[8,1,20,27,11],[9,4,6,2,21],[40,9,1,10,6],[22,7,4,5,3]]
//Output: 3
//Explanation: The grid on the left shows a valid cornered path.
//It has a product of 15 * 20 * 6 * 1 * 10 = 18000 which has 3 trailing zeros.
//It can be shown that this is the maximum trailing zeros in the product of a cornered path.
//The grid in the middle is not a cornered path as it has more than one turn.
//The grid on the right is not a cornered path as it requires a return to a previously visited cell.
//Example 2:
//Input: grid = [[4,3,2],[7,6,1],[8,8,8]]
//Output: 0
//Explanation: The grid is shown in the figure above.
//There are no cornered paths in the grid that result in a product with a trailing zero.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 105
//	1 <= m * n <= 105
//	1 <= grid[i][j] <= 1000
/**
 * @param {number[][]} grid
 * @return {number}
 */ 
var maxTrailingZeros = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    
    // Helper function to count factors of 2 and 5
    function getFactors(num) {
        let twos = 0, fives = 0;
        while (num % 2 === 0) {
            twos++;
            num = Math.floor(num / 2);
        }
        while (num % 5 === 0) {
            fives++;
            num = Math.floor(num / 5);
        }
        return [twos, fives];
    }
    
    // Create prefix sum arrays for both horizontal and vertical directions
    // Each cell stores [twos, fives]
    const left = Array(m).fill().map(() => Array(n).fill().map(() => [0, 0]));
    const right = Array(m).fill().map(() => Array(n).fill().map(() => [0, 0]));
    const up = Array(m).fill().map(() => Array(n).fill().map(() => [0, 0]));
    const down = Array(m).fill().map(() => Array(n).fill().map(() => [0, 0]));
    
    // Fill the factor counts for each cell
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const [twos, fives] = getFactors(grid[i][j]);
            
            // Left to right
            left[i][j][0] = twos + (j > 0 ? left[i][j-1][0] : 0);
            left[i][j][1] = fives + (j > 0 ? left[i][j-1][1] : 0);
            
            // Top to bottom
            up[i][j][0] = twos + (i > 0 ? up[i-1][j][0] : 0);
            up[i][j][1] = fives + (i > 0 ? up[i-1][j][1] : 0);
        }
    }
    
    // Fill right to left
    for (let i = 0; i < m; i++) {
        for (let j = n-1; j >= 0; j--) {
            const [twos, fives] = getFactors(grid[i][j]);
            right[i][j][0] = twos + (j < n-1 ? right[i][j+1][0] : 0);
            right[i][j][1] = fives + (j < n-1 ? right[i][j+1][1] : 0);
        }
    }
    
    // Fill bottom to top
    for (let i = m-1; i >= 0; i--) {
        for (let j = 0; j < n; j++) {
            const [twos, fives] = getFactors(grid[i][j]);
            down[i][j][0] = twos + (i < m-1 ? down[i+1][j][0] : 0);
            down[i][j][1] = fives + (i < m-1 ? down[i+1][j][1] : 0);
        }
    }
    
    let maxZeros = 0;
    
    // Check all possible corner points
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const [cellTwos, cellFives] = getFactors(grid[i][j]);
            
            // Check all four possible paths through current cell
            // Left-Up, Left-Down, Right-Up, Right-Down
            const paths = [
                [
                    left[i][j][0] + up[i][j][0] - cellTwos,
                    left[i][j][1] + up[i][j][1] - cellFives
                ],
                [
                    left[i][j][0] + down[i][j][0] - cellTwos,
                    left[i][j][1] + down[i][j][1] - cellFives
                ],
                [
                    right[i][j][0] + up[i][j][0] - cellTwos,
                    right[i][j][1] + up[i][j][1] - cellFives
                ],
                [
                    right[i][j][0] + down[i][j][0] - cellTwos,
                    right[i][j][1] + down[i][j][1] - cellFives
                ]
            ];
            
            // Update maximum trailing zeros
            for (const [twos, fives] of paths) {
                maxZeros = Math.max(maxZeros, Math.min(twos, fives));
            }
        }
    }
    
    return maxZeros;
};
/**https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/ */
//You are given an m x n integer matrix grid​​​.
//A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:
//Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.
//Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.
// 
//Example 1:
//Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
//Output: [228,216,211]
//Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
//- Blue: 20 + 3 + 200 + 5 = 228
//- Red: 200 + 2 + 10 + 4 = 216
//- Green: 5 + 200 + 4 + 2 = 211
//Example 2:
//Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [20,9,8]
//Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
//- Blue: 4 + 2 + 6 + 8 = 20
//- Red: 9 (area 0 rhombus in the bottom right corner)
//- Green: 8 (area 0 rhombus in the bottom middle)
//Example 3:
//Input: grid = [[7,7,7]]
//Output: [7]
//Explanation: All three possible rhombus sums are the same, so return [7].
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	1 <= grid[i][j] <= 105
/**
 * @param {number[][]} grid
 * @return {number[]}
 */
var getBiggestThree = function(grid) {
    const m = grid.length, n = grid[0].length;
    const sums = new Set();
    
    // Calculate rhombus sums for each possible center
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            // Check all possible sizes of rhombus
            for (let size = 0; size < Math.min(m, n); size++) {
                let sum = 0;
                let valid = true;
                
                // Calculate the sum of the rhombus
                for (let k = -size; k <= size; k++) {
                    const row = i + k;
                    const col1 = j + (size - Math.abs(k));
                    const col2 = j - (size - Math.abs(k));
                    
                    if (row < 0 || row >= m || col1 < 0 || col1 >= n || col2 < 0 || col2 >= n) {
                        valid = false;
                        break;
                    }
                    
                    sum += grid[row][col1];
                    if (col1 !== col2) sum += grid[row][col2];
                }
                
                if (valid) sums.add(sum);
            }
        }
    }
    
    // Convert to array and sort in descending order
    const result = Array.from(sums).sort((a, b) => b - a);
    
    // Return the top 3 or less
    return result.slice(0, 3);    
};
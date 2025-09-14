/**https://leetcode.com/problems/strange-printer-ii/ */
//There is a strange printer with the following two special requirements:
//	On each turn, the printer will print a solid rectangular pattern of a single color on the grid. This will cover up the existing colors in the rectangle.
//	Once the printer has used a color for the above operation, the same color cannot be used again.
//You are given a m x n matrix targetGrid, where targetGrid[row][col] is the color in the position (row, col) of the grid.
//Return true if it is possible to print the matrix targetGrid, otherwise, return false.
// 
//Example 1:
//Input: targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
//Output: true
//Example 2:
//Input: targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
//Output: true
//Example 3:
//Input: targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
//Output: false
//Explanation: It is impossible to form targetGrid because it is not allowed to print the same color in different turns.
// 
//Constraints:
//	m == targetGrid.length
//	n == targetGrid[i].length
//	1 <= m, n <= 60
//	1 <= targetGrid[row][col] <= 60
/**
 * @param {number[][]} targetGrid
 * @return {boolean}
 */
var isPrintable = function(targetGrid) {
    // Your code here
    // Initialize a 2D array to store the frequency of each color
    let freq = Array.from({length: 61}, () => Array(61).fill(0));
    
    // Initialize a 2D array to store the minimum and maximum coordinates of each color
    let minMax = Array.from({length: 61}, () => Array(4).fill(Infinity));
    
    // Initialize a boolean array to track the colors used
    let usedColors = Array(61).fill(false);
    
    // Iterate through the targetGrid to find the minimum and maximum coordinates of each color
    for (let i = 0; i < targetGrid.length; i++) {
        for (let j = 0; j < targetGrid[0].length; j++) {
            let color = targetGrid[i][j];
            minMax[color][0] = Math.min(minMax[color][0], i);
            minMax[color][1] = Math.min(minMax[color][1], j);
            minMax[color][2] = Math.max(minMax[color][2], i);
            minMax[color][3] = Math.max(minMax[color][3], j);
        }
    }
    
    // Helper function to check if a color can be placed in a given position
    function canPlace(color, row, col) {
        let [minX, minY, maxX, maxY] = minMax[color];
        for (let i = minX; i <= maxX; i++) {
            for (let j = minY; j <= maxY; j++) {
                if (targetGrid[i][j] === color) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // Helper function to fill the grid with the given color
    function fillGrid(color, row, col) {
        let [minX, minY, maxX, maxY] = minMax[color];
        for (let i = minX; i <= maxX; i++) {
            for (let j = minY; j <= maxY; j++) {
                targetGrid[i][j] = color;
            }
        }
    }
    
    // Helper function to check if the grid is filled
    function isFilled() {
        for (let i = 0; i < targetGrid.length; i++) {
            for (let j = 0; j < targetGrid[0].length; j++) {
                if (targetGrid[i][j] === 0) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // Helper function to calculate the number of connected components
    function countComponents() {
        let count = 0;
        for (let i = 1; i <= 60; i++) {
            if (!usedColors[i]) {
                count++;
                dfs(i);
            }
        }
        return count;
    }
    
    // Helper function to perform depth-first search
    function dfs(color) {
        usedColors[color] = true;
        for (let i = 1; i <= 60; i++) {
            if (canPlace(i, minMax[color][0], minMax[color][1]) &&!usedColors[i]) {
                dfs(i);
            }
        }
    }
    
    // Iterate through the targetGrid to fill the grid with the colors
    for (let i = 0; i < targetGrid.length; i++) {
        for (let j = 0; j < targetGrid[0].length; j++) {
            let color = targetGrid[i][j];
            if (canPlace(color, i, j)) {
                fillGrid(color, i, j);
                usedColors[color] = true;
                dfs(color);
            }
        }
    }
    
    // Check if the grid is filled and has the correct number of connected components
    return isFilled() && countComponents() === 1;
    
};
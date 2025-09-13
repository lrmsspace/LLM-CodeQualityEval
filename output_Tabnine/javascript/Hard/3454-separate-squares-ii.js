/*
 You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.
 Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.
 Answers within 10-5 of the actual answer will be accepted.
 Note: Squares may overlap. Overlapping areas should be counted only once in this version.
 Example 1:
 Input: squares = [[0,0,1],[2,2,1]]
 Output: 1.00000
 Explanation:
 Any horizontal line between y = 1 and y = 2 results in an equal split, with 1 square unit above and 1 square unit below. The minimum y-value is 1.
 Example 2:
 Input: squares = [[0,0,2],[1,1,1]]
 Output: 1.00000
 Explanation:
 Since the blue square overlaps with the red square, it will not be counted again. Thus, the line y = 1 splits the squares into two equal parts.
 Constraints:
 1 <= squares.length <= 5 * 104
 squares[i] = [xi, yi, li]
 squares[i].length == 3
 0 <= xi, yi <= 109
 1 <= li <= 109
 The total area of all the squares will not exceed 1015.
*/

/**
 * @param {number[][]} squares
 * @return {number}
 */
var separateSquares = function(squares) {
    // Sort the squares by their x-coordinate in ascending order
    squares.sort((a, b) => a[0] - b[0]);
    
    // Initialize the variables
    let maxArea = 0;
    let left = 0;
    let right = squares.length - 1;
    
    // Iterate through the squares
    while (left < right) {
        // Calculate the area of the current square
        let area = squares[left][2] * squares[right][2];
        
        // Update the maximum area if necessary
        maxArea = Math.max(maxArea, area);
        
        // Check if the sum of the areas of the two squares is greater than or equal to the area of the current square
        if (squares[left][2] + squares[right][2] >= squares[left][1]) {
            left++;
        } else {
            right--;
        }
    }
    
    // Return the minimum y-coordinate value
    return maxArea;
    
};
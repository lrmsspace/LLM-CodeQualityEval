/**https://leetcode.com/problems/maximal-rectangle/ */
//Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// 
//Example 1:
//Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//Output: 6
//Explanation: The maximal rectangle is shown in the above picture.
//Example 2:
//Input: matrix = [["0"]]
//Output: 0
//Example 3:
//Input: matrix = [["1"]]
//Output: 1
// 
//Constraints:
//	rows == matrix.length
//	cols == matrix[i].length
//	1 <= row, cols <= 200
//	matrix[i][j] is '0' or '1'.
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    int maxArea = 0;
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int heights[cols];
    memset(heights, 0, sizeof(heights));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        int stack[cols + 1];
        int top = -1;
        for (int j = 0; j < cols; j++) {
            while (top >= 0 && heights[stack[top]] > heights[j]) {
                int h = heights[stack[top--]];
                int w = top < 0 ? j : j - stack[top] - 1;
                maxArea = fmax(maxArea, h * w);
            }
            stack[++top] = j;
        }
        while (top >= 0) {
            int h = heights[stack[top--]];
            int w = top < 0 ? cols : cols - stack[top] - 1;
            maxArea = fmax(maxArea, h * w);
        }
    }
    return maxArea;
    
}
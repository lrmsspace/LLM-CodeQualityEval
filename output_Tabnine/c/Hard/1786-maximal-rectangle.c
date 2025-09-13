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
    int* heights = (int*)malloc(matrixColSize[0] * sizeof(int));
    
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            heights[j] = matrix[i][j] == '1'? heights[j] + 1 : 0;
        }
        maxArea = max(maxArea, largestRectangleArea(heights, matrixColSize[0]));
    }
    
    free(heights);
    return maxArea;
    
}
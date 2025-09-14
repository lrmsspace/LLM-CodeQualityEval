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
    int *heights = (int *)malloc(matrixSize * sizeof(int));
    memset(heights, 0, matrixSize * sizeof(int));
    for (int j = 0; j < *matrixColSize; j++) {
        for (int i = 0; i < matrixSize; i++) {
            if (matrix[i][j] == '1')
                heights[i]++;
            else
                heights[i] = 0;
        }
        int stack[matrixSize];
        int top = -1;
        int i = 0;
        while (i < matrixSize) {
            if (top == -1 || heights[i] >= heights[stack[top]]) {
                top++;
                stack[top] = i++;
            } else {
                int height = heights[stack[top--]];
                int width = top == -1 ? i : i - stack[top] - 1;
                maxArea = fmax(maxArea, height * width);
            }
        }
        while (top != -1) {
            int height = heights[stack[top--]];
            int width = top == -1 ? i : matrixSize - stack[top] - 1;
            maxArea = fmax(maxArea, height * width);
        }
    }
    free(heights);
    return maxArea;
}
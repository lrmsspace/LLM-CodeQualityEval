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
    if (matrixSize == 0) {
        return 0;
    }
    int row = matrixSize, col = *matrixColSize;
    int left[col], right[col], height[col];
    for (int i = 0; i < col; i++) {
        left[i] = 0;
        right[i] = col;
        height[i] = 0;
    }
    int maxArea = 0;
    for (int i = 0; i < row; i++) {
        int curLeft = 0, curRight = col;
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == '1') {
                height[j]++;
            } else {
                height[j] = 0;
            }
        }
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == '1') {
                left[j] = fmax(left[j], curLeft);
            } else {
                left[j] = 0;
                curLeft = j + 1;
            }
        }
        for (int j = col - 1; j >= 0; j--) {
            if (matrix[i][j] == '1') {
                right[j] = fmin(right[j], curRight);
            } else {
                right[j] = col;
                curRight = j;
            }
        }
        for (int j = 0; j < col; j++) {
            maxArea = fmax(maxArea, (right[j] - left[j]) * height[j]);
        }
    }
    return maxArea;    
}
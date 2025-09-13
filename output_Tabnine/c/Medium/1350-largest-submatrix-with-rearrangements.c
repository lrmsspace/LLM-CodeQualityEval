/**https://leetcode.com/problems/largest-submatrix-with-rearrangements/ */
//You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
//Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.
// 
//Example 1:
//Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
//Output: 4
//Explanation: You can rearrange the columns as shown above.
//The largest submatrix of 1s, in bold, has an area of 4.
//Example 2:
//Input: matrix = [[1,0,1,0,1]]
//Output: 3
//Explanation: You can rearrange the columns as shown above.
//The largest submatrix of 1s, in bold, has an area of 3.
//Example 3:
//Input: matrix = [[1,1,0],[1,0,1]]
//Output: 2
//Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m * n <= 105
//	matrix[i][j] is either 0 or 1.
int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int res = 0;
    
    int* height = (int*)malloc(sizeof(int) * n);
    int* left = (int*)malloc(sizeof(int) * n);
    int* right = (int*)malloc(sizeof(int) * n);
    
    for (int i = 0; i < m; ++i) {
        int cur_left = 0, cur_right = n - 1;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) height[j]++;
            else height[j] = 0;
            
            if (matrix[i][j] == 1) left[j] = (j == 0)? 0 : left[j - 1] + 1;
            else left[j] = 0;
            
            while (cur_left < j && height[cur_left] >= height[j]) cur_left++;
            while (cur_right > j && height[cur_right] >= height[j]) cur_right--;
            
            right[j] = cur_right - cur_left + 1;
        }
        
        for (int j = 0; j < n; ++j) {
            res = fmax(res, height[j] * right[j]);
        }
        
        free(height);
        free(left);
        free(right);
        height = (int*)malloc(sizeof(int) * n);
        left = (int*)malloc(sizeof(int) * n);
        right = (int*)malloc(sizeof(int) * n);
        memcpy(height, matrix[i], sizeof(int) * n);
        memcpy(left, matrix[i], sizeof(int) * n);
        memcpy(right, matrix[i], sizeof(int) * n);
        for (int j = 0; j < n; ++j) {
            height[j] = 0;
            left[j] = 0;
            right[j] = 0;
        }
    }
    return res;
    
}
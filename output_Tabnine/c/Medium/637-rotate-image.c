/**https://leetcode.com/problems/rotate-image/ */
//You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
//You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
// 
//Example 1:
//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [[7,4,1],[8,5,2],[9,6,3]]
//Example 2:
//Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
//Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
// 
//Constraints:
//	n == matrix.length == matrix[i].length
//	1 <= n <= 20
//	-1000 <= matrix[i][j] <= 1000
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;
    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            int top = matrix[first][i]; // save top
            
            // left -> top
            matrix[first][i] = matrix[last - offset][first];
            
            // bottom -> left
            matrix[last - offset][first] = matrix[last][last - offset];
            
            // right -> bottom
            matrix[last][last - offset] = matrix[i][last];
            
            // top -> right
            matrix[i][last] = top; // restore top
        }
    }
    return;
    
}
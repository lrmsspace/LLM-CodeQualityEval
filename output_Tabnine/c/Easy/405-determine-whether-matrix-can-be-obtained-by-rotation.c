/**https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/ */
//Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
// 
//Example 1:
//Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
//Output: true
//Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
//Example 2:
//Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
//Output: false
//Explanation: It is impossible to make mat equal to target by rotating mat.
//Example 3:
//Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
//Output: true
//Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
// 
//Constraints:
//	n == mat.length == target.length
//	n == mat[i].length == target[i].length
//	1 <= n <= 10
//	mat[i][j] and target[i][j] are either 0 or 1.
bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
    // Check if the matrices are the same size
    if (matSize!= targetSize || matColSize[0]!= targetColSize[0]) {
        return false;
    }
    
    // Check if the matrices are equal
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[0]; j++) {
            if (mat[i][j]!= target[j][matSize - i - 1]) {
                return false;
            }
        }
    }
    
    // Check if the matrices can be obtained by rotating mat 90 degrees clockwise
    for (int i = 0; i < matSize; i++) {
        for (int j = i; j < matColSize[0]; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][matSize - i - 1];
            mat[j][matSize - i - 1] = temp;
        }
    }
    
    return true;
}
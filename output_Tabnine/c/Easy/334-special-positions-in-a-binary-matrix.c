/**https://leetcode.com/problems/special-positions-in-a-binary-matrix/ */
//Given an m x n binary matrix mat, return the number of special positions in mat.
//A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).
// 
//Example 1:
//Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
//Output: 1
//Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
//Example 2:
//Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
//Output: 3
//Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 100
//	mat[i][j] is either 0 or 1.
int numSpecial(int** mat, int matSize, int* matColSize) {
    int result = 0;
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 1) {
                bool isSpecial = true;
                for (int k = 0; k < matSize; k++) {
                    if (mat[k][j] == 1) {
                        isSpecial = false;
                        break;
                    }
                }
                for (int k = 0; k < matColSize[i]; k++) {
                    if (mat[i][k] == 1 && k!= j) {
                        isSpecial = false;
                        break;
                    }
                }
                if (isSpecial) {
                    result++;
                }
            }
        }
    }
    return result;
    
}
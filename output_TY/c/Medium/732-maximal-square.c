/**https://leetcode.com/problems/maximal-square/ */
//Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
// 
//Example 1:
//Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//Output: 4
//Example 2:
//Input: matrix = [["0","1"],["1","0"]]
//Output: 1
//Example 3:
//Input: matrix = [["0"]]
//Output: 0
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 300
//	matrix[i][j] is '0' or '1'.
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int i,j,k;
    int max = 0;
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize[i];j++){
            if(matrix[i][j]=='1'){
                for(k=1;k<=matrixColSize[i]-j;k++){
                    if(matrix[i+k-1][j+k-1]=='0'){
                        break;
                    }
                }
            }
        }
    }
    return max*max;
}
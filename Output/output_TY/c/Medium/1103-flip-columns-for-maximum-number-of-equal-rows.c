/**https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/ */
//You are given an m x n binary matrix matrix.
//You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).
//Return the maximum number of rows that have all values equal after some number of flips.
// 
//Example 1:
//Input: matrix = [[0,1],[1,1]]
//Output: 1
//Explanation: After flipping no values, 1 row has all values equal.
//Example 2:
//Input: matrix = [[0,1],[1,0]]
//Output: 2
//Explanation: After flipping values in the first column, both rows have equal values.
//Example 3:
//Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
//Output: 2
//Explanation: After flipping values in the first two columns, the last two rows have equal values.
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 300
//	matrix[i][j] is either 0 or 1.
int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int count=0;
    int max=0;
    int *arr=(int *)malloc(matrixSize*matrixColSize[0]*sizeof(int));
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize[0];j++){
            arr[i*matrixColSize[0]+j]=matrix[i][j];
            if(i==0){
                count++;
            }
        }
    }
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize[0];j++){
            if(matrix[i][0]==1){
                matrix[i][j]=1-matrix[i][j];
            }
        }
    }
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize[0];j++){
            arr[i*matrixColSize[0]+j]=matrix[i][j];
        }
    }
    for(i=0;i<matrixSize;i++){
        for(j=i+1;j<matrixSize;j++){
            for(k=0;k<matrixColSize[0];k++){
                if(arr[i*matrixColSize[0]+k]==arr[j*matrixColSize[0]+k]){
                    count++;
                }
            }
            if(count==matrixColSize[0]){
                max=count>max?count:max;
            }
        }
    }
    return max;
}
/**https://leetcode.com/problems/pascals-triangle/ */
//Given an integer numRows, return the first numRows of Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
// 
//Example 1:
//Input: numRows = 5
//Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
//Example 2:
//Input: numRows = 1
//Output: [[1]]
// 
//Constraints:
//	1 <= numRows <= 30
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int i,j;
    int **res;
    *returnSize=numRows;
    res=(int**)malloc(sizeof(int*)*numRows);
    for(i=0;i<numRows;i++){
        res[i]=(int*)malloc(sizeof(int)*(i+1));
        res[i][0]=1;
        res[i][i]=1;
        for(j=1;j<i;j++){
            res[i][j]=res[i-1][j-1]+res[i-1][j];
            res[i][i]=1;
            returnColumnSizes[i]=i+1;
            return res;
        }
        returnColumnSizes[i]=i+1;
        return res;
    }
}
/**https://leetcode.com/problems/cyclically-rotating-a-grid/ */
//You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k._x000D_
//_x000D_
//The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:_x000D_
//_x000D_
//_x000D_
//_x000D_
//A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:_x000D_
//_x000D_
//Return the matrix after applying k cyclic rotations to it._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: grid = [[40,10],[30,20]], k = 1_x000D_
//Output: [[10,20],[40,30]]_x000D_
//Explanation: The figures above represent the grid at every state._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//  _x000D_
//_x000D_
//_x000D_
//Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2_x000D_
//Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]_x000D_
//Explanation: The figures above represent the grid at every state._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	m == grid.length_x000D_
//	n == grid[i].length_x000D_
//	2 <= m, n <= 50_x000D_
//	Both m and n are even integers._x000D_
//	1 <= grid[i][j] <= 5000_x000D_
//	1 <= k <= 109_x000D_
/**_x000D_
 * Return an array of arrays of size *returnSize._x000D_
 * The sizes of the arrays are returned as *returnColumnSizes array._x000D_
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free()._x000D_
 */_x000D_
int** rotateGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    int i,j,k,l,m,n,p,q,r,s,t,u,v,w,x,y,z,a,b,c,d,e,f,g,h,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk,ll,mm,nn,oo,pp,qq,rr   ;
    int *returnColumnSizes = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        returnColumnSizes[i] = gridColSize[i];
    }
    *returnSize = gridSize;
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[i];j++){
            printf("%d ",grid[i][j]);
        }
    }
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[i];j++){
            printf("%d ",grid[i][j]);
        }
    }
    return grid;
}
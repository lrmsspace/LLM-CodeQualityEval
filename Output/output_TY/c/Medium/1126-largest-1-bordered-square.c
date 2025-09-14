/**https://leetcode.com/problems/largest-1-bordered-square/ */
//Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]_x000D_
//Output: 9_x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: grid = [[1,1,0,0]]_x000D_
//Output: 1_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= grid.length <= 100_x000D_
//	1 <= grid[0].length <= 100_x000D_
//	grid[i][j] is 0 or 1_x000D_


int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize){
    int i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int max=0;
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[i];j++){
            if(grid[i][j]==1){
                for(k=i;k>=0;k--){
                    for(l=j;l>=0;l--){
                        if(grid[k][l]==1){
                            for(m=i;m<gridSize;m++){
                                for(n=j;n<gridColSize[i];n++){
                                    if(grid[m][n]==1){
                                        if(m-k+1==n-l+1){
                                           if(m-k+1>max){
                                             max=m-k+1;
                                           }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return max*max;
}
/**https://leetcode.com/problems/number-of-islands/ */
//Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
//An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
// 
//Example 1:
//Input: grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//Output: 1
//Example 2:
//Input: grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//Output: 3
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 300
//	grid[i][j] is '0' or '1'.
int numIslands(char** grid, int gridSize, int* gridColSize){
    int i,j,k,l,m,n,count=0;
    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[i];j++){
            if(grid[i][j]=='1'){
                count++;
                for(k=i-1;k<=i+1;k++){
                    for(l=j-1;l<=j+1;l++){
                        if(k>=0&&k<gridSize&&l>=0&&l<gridColSize[i]&&grid[k][l]=='1'){
                            grid[k][l]='0';
                        }
                    }
                }
            }
        }
    }
    return count;
}
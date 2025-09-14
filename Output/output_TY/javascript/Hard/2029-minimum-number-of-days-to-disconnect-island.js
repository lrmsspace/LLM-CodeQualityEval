/**https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/ */
//You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
//The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
//In one day, we are allowed to change any single land cell (1) into a water cell (0).
//Return the minimum number of days to disconnect the grid.
// 
//Example 1:
//Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
//Output: 2
//Explanation: We need at least 2 days to get a disconnected grid.
//Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
//Example 2:
//Input: grid = [[1,1]]
//Output: 2
//Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 30
//	grid[i][j] is either 0 or 1.
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minDays = function(grid) {
    let n = grid.length;
    let m = grid[0].length;
    let count = 0;
    for(let i=0;i<n;i++){
        for(let j=0;j<m;j++){
            if(grid[i][j]==1){
                count++;
            }
        }
    }
    if(count==0){
        return 0;
    }
    let ans = 1;
    while(ans<=n*m){
        let visited = new Array(n).fill(0).map(()=>new Array(m).fill(0));
        let count1 = 0;
        for(let i=0;i<n;i++){
            for(let j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    count1++;
                    dfs(i,j,visited);
                }
            }
        }
        if(count1>1){
            return ans;
        }
        for(let i=0;i<n;i++){
            for(let j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    let count2=0;
                    for(let k=0;k<n;k++){
                        for(let l=0;l<m;l++){
                            if(grid[k][l]==1 && visited[k][l]==0){
                                count2++;
                                dfs(k,l,visited);
                            }
                        }
                    }
                    ans=Math.max(ans,count2);
                    grid[i][j]=1;
                }
            }
        }
    }
    return ans;
};
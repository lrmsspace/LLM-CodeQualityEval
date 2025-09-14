/**https://leetcode.com/problems/number-of-enclaves/ */
//You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
//A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
//Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
// 
//Example 1:
//Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
//Output: 3
//Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
//Example 2:
//Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
//Output: 0
//Explanation: All 1s are either on the boundary or can reach the boundary.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 500
//	grid[i][j] is either 0 or 1.
/**
 * @param {number[][]} grid
 * @return {number}
 */
var numEnclaves = function(grid) {
    let m = grid.length, n = grid[0].length;
    let visited = new Array(m).fill(0).map(()=>new Array(n).fill(false));
    let queue = [];
    for(let i=0;i<m;i++){
        for(let j=0;j<n;j++){
            if(grid[i][j]===1 && visited[i][j]===false){
                queue.push([i,j]);
                visited[i][j]=true;
                while(queue.length){
                    let [x,y] = queue.shift();
                    if(x-1>=0 && grid[x-1][y]===1 && visited[x-1][y]===false){
                       queue.push([x-1,y]);
                    }
                }
            }
        }
    }
    return m*n - queue.length;
};
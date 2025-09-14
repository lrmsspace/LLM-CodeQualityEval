/**https://leetcode.com/problems/shortest-bridge/ */
//You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
//An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
//You may change 0's to 1's to connect the two islands to form one island.
//Return the smallest number of 0's you must flip to connect the two islands.
// 
//Example 1:
//Input: grid = [[0,1],[1,0]]
//Output: 1
//Example 2:
//Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
//Output: 2
//Example 3:
//Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
//Output: 1
// 
//Constraints:
//	n == grid.length == grid[i].length
//	2 <= n <= 100
//	grid[i][j] is either 0 or 1.
//	There are exactly two islands in grid.
/**
 * @param {number[][]} grid
 * @return {number}
 */
var shortestBridge = function(grid) {
    let n = grid.length;
    let queue = [];
    for(let i=0;i<n;i++){
        for(let j=0;j<n;j++){
            if(grid[i][j]===1){
                dfs(grid,i,j,queue);
                break;
            }
        }
    }
    let step = 0;
        while(queue.length){
            let size = queue.length;
            for(let i=0;i<size;i++){
                let [x,y] = queue.shift();
                for(let [dx,dy] of [[0,1],[0,-1],[1,0],[-1,0]]){
                    let nx = x+dx;
                    let ny = y+dy;
                    if(nx>=0 && nx<n && ny>=0 && ny<n){
                        if(grid[nx][ny]===1){
                            return step;
                        }
                        if(grid[nx][ny]===0){
                            grid[nx][ny] = -1;
                            queue.push([nx,ny]);
                        }
                    }
                }
            }
            step++;
        }
        return -1;
};
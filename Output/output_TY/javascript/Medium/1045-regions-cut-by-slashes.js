/**https://leetcode.com/problems/regions-cut-by-slashes/ */
//An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.
//Given the grid grid represented as a string array, return the number of regions.
//Note that backslash characters are escaped, so a '\' is represented as '\\'.
// 
//Example 1:
//Input: grid = [" /","/ "]
//Output: 2
//Example 2:
//Input: grid = [" /","  "]
//Output: 1
//Example 3:
//Input: grid = ["/\\","\\/"]
//Output: 5
//Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
// 
//Constraints:
//	n == grid.length == grid[i].length
//	1 <= n <= 30
//	grid[i][j] is either '/', '\', or ' '.
/**
 * @param {string[]} grid
 * @return {number}
 */
var regionsBySlashes = function(grid) {
    var n = grid.length;
    var parent = new Array(n*n*4);
    for(var i=0;i<n*n*4;i++){
        parent[i] = i;
    }
    
    var find = function(x){
        if(parent[x]===x){
            return x;
        }
        return find(parent[x]);
    }
    
    var union = function(x,y){
        var xRoot = find(x);
        var yRoot = find(y);
        if(xRoot!==yRoot){
            parent[yRoot] = xRoot;
        }
    }
    
    for(var i=0;i<n;i++){
        for(var j=0;j<n;j++){
            if(grid[i][j]==='/'){
                union(i*n*4+j*4+0,i*n*4+j*4+1);
                union(i*n*4+j*4+3,i*n*4+j*4+2);
            }else if(grid[i][j]==='\\'){
                union(i*n*4+j*4+0,i*n*4+j*4+2);
                union(i*n*4+j*4+1,i*n*4+j*4+3);
            }
           if(i+1<n){
              union(i*n*4+j*4+2,i*n*4+(j+1)*4+0);
           }
        }
    }
    var count = 0;
    for(var i=0;i<n*n*4;i++){
        if(parent[i]===i){
            count++;
        }
    }
    return count;
};
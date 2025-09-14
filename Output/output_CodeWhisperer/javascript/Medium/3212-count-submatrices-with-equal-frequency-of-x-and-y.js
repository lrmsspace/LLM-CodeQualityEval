/*
 Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
 grid[0][0]
 an equal frequency of 'X' and 'Y'.
 at least one 'X'.
 Example 1:
 Input: grid = [["X","Y","."],["Y",".","."]]
 Output: 3
 Explanation:
 Example 2:
 Input: grid = [["X","X"],["X","Y"]]
 Output: 0
 Explanation:
 No submatrix has an equal frequency of 'X' and 'Y'.
 Example 3:
 Input: grid = [[".","."],[".","."]]
 Output: 0
 Explanation:
 No submatrix has at least one 'X'.
 Constraints:
 1 <= grid.length, grid[i].length <= 1000
 grid[i][j] is either 'X', 'Y', or '.'.
*/

/**
 * @param {character[][]} grid
 * @return {number}
 */
var numberOfSubmatrices = function(grid) {
    let count = 0;
    for(let i = 0; i < grid.length; i++) {
        for(let j = 0; j < grid[0].length; j++) {
            if(grid[i][j] === 'X') {
                count++;
                let x = i + 1;
                let y = j + 1;
                while(x < grid.length && y < grid[0].length) {
                    if(grid[x][j] === 'X' && grid[i][y] === 'X') {
                        count++;
                    }
                    x++;
                    y++;
                }
            }
        }
    }
    return count;    
};
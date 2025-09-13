/**https://leetcode.com/problems/difference-of-number-of-distinct-values-on-diagonals/ */
//Given a 2D grid of size m x n, you should find the matrix answer of size m x n.
//The cell answer[r][c] is calculated by looking at the diagonal values of the cell grid[r][c]:
//	Let leftAbove[r][c] be the number of distinct values on the diagonal to the left and above the cell grid[r][c] not including the cell grid[r][c] itself.
//	Let rightBelow[r][c] be the number of distinct values on the diagonal to the right and below the cell grid[r][c], not including the cell grid[r][c] itself.
//	Then answer[r][c] = |leftAbove[r][c] - rightBelow[r][c]|.
//A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until the end of the matrix is reached.
//	For example, in the below diagram the diagonal is highlighted using the cell with indices (2, 3) colored gray:
//	
//		Red-colored cells are left and above the cell.
//		Blue-colored cells are right and below the cell.
//	
//	
//Return the matrix answer.
// 
//Example 1:
//Input: grid = [[1,2,3],[3,1,5],[3,2,1]]
//Output: Output: [[1,1,0],[1,0,1],[0,1,1]]
//Explanation:
//To calculate the answer cells:
//	
//		
//			answer
//			left-above elements
//			leftAbove
//			right-below elements
//			rightBelow
//			|leftAbove - rightBelow|
//		
//	
//	
//		
//			[0][0]
//			[]
//			0
//			[grid[1][1], grid[2][2]]
//			|{1, 1}| = 1
//			1
//		
//		
//			[0][1]
//			[]
//			0
//			[grid[1][2]]
//			|{5}| = 1
//			1
//		
//		
//			[0][2]
//			[]
//			0
//			[]
//			0
//			0
//		
//		
//			[1][0]
//			[]
//			0
//			[grid[2][1]]
//			|{2}| = 1
//			1
//		
//		
//			[1][1]
//			[grid[0][0]]
//			|{1}| = 1
//			[grid[2][2]]
//			|{1}| = 1
//			0
//		
//		
//			[1][2]
//			[grid[0][1]]
//			|{2}| = 1
//			[]
//			0
//			1
//		
//		
//			[2][0]
//			[]
//			0
//			[]
//			0
//			0
//		
//		
//			[2][1]
//			[grid[1][0]]
//			|{3}| = 1
//			[]
//			0
//			1
//		
//		
//			[2][2]
//			[grid[0][0], grid[1][1]]
//			|{1, 1}| = 1
//			[]
//			0
//			1
//		
//	
//Example 2:
//Input: grid = [[1]]
//Output: Output: [[0]]
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n, grid[i][j] <= 50
/**
 * @param {number[][]} grid
 * @return {number[][]}
 */
var differenceOfDistinctValues = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    const leftAbove = new Array(m).fill(0).map(() => new Array(n).fill(0));
    const rightBelow = new Array(m).fill(0).map(() => new Array(n).fill(0));
    const set = new Set();
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            set.clear();
            let x = i - 1;
            let y = j - 1;
            while (x >= 0 && y >= 0) {
                set.add(grid[x][y]);
            }
        }
    }
    leftAbove[0][0] = set.size;
    for (let i = 1; i < m; i++) {
        set.clear();
        let x = i - 1;
        let y = 0;
        while (x >= 0 && y < n) {
            set.add(grid[x][y]);
        }
        leftAbove[i][0] = set.size;
    }
    for (let j = 1; j < n; j++) {
        set.clear();
        let x = 0;
        let y = j - 1;
        while (x < m && y >= 0) {
            set.add(grid[x][y]);
        }
        leftAbove[0][j] = set.size;
    }
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            set.clear();
            let x = i - 1;
            let y = j - 1;
            while (x >= 0 && y >= 0) {
                set.add(grid[x][y]);
            }
            leftAbove[i][j] = set.size;
        }
    }
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            set.clear();
            let x = i + 1;
            let y = j + 1;
            while (x < m && y < n) {
                set.add(grid[x][y]);
            }
        }
    }   
    rightBelow[m - 1][n - 1] = set.size;
    for (let i = m - 2; i >= 0; i--) {
        set.clear();
        let x = i + 1;
        let y = n - 1;
        while (x < m && y >= 0) {
            set.add(grid[x][y]);
        }
        rightBelow[i][n - 1] = set.size;
    }
    for (let j = n - 2; j >= 0; j--) {
        set.clear();
        let x = m - 1;
        let y = j + 1;
        while (x >= 0 && y < n) {
            set.add(grid[x][y]);
        }
        rightBelow[m - 1][j] = set.size;
    }
    for (let i = m - 2; i >= 0; i--) {
        for (let j = n - 2; j >= 0; j--) {
            set.clear();
            let x = i + 1;
            let y = j + 1;
            while (x < m && y < n) {
                set.add(grid[x][y]);
            }
            rightBelow[i][j] = set.size;
        }
    }
    const answer = new Array(m).fill(0).map(() => new Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            answer[i][j] = Math.abs(leftAbove[i][j] - rightBelow[i][j]);
        }
    }
    return answer;
};
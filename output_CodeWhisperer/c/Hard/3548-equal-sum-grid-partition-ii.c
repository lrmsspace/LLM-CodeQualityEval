/*
 You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:
 Each of the two resulting sections formed by the cut is non-empty.
 The sum of elements in both sections is equal, or can be made equal by discounting at most one single cell in total (from either section).
 If a cell is discounted, the rest of the section must remain connected.
 Return true if such a partition exists; otherwise, return false.
 Note: A section is connected if every cell in it can be reached from any other cell by moving up, down, left, or right through other cells in the section.
 Example 1:
 Input: grid = [[1,4],[2,3]]
 Output: true
 Explanation:
 A horizontal cut after the first row gives sums 1 + 4 = 5 and 2 + 3 = 5, which are equal. Thus, the answer is true.
 Example 2:
 Input: grid = [[1,2],[3,4]]
 Output: true
 Explanation:
 A vertical cut after the first column gives sums 1 + 3 = 4 and 2 + 4 = 6.
 By discounting 2 from the right section (6 - 2 = 4), both sections have equal sums and remain connected. Thus, the answer is true.
 Example 3:
 Input: grid = [[1,2,4],[2,3,5]]
 Output: false
 Explanation:
 A horizontal cut after the first row gives 1 + 2 + 4 = 7 and 2 + 3 + 5 = 10.
 By discounting 3 from the bottom section (10 - 3 = 7), both sections have equal sums, but they do not remain connected as it splits the bottom section into two parts ([2] and [5]). Thus, the answer is false.
 Example 4:
 Input: grid = [[4,1,8],[3,2,6]]
 Output: false
 Explanation:
 No valid cut exists, so the answer is false.
 Constraints:
 1 <= m == grid.length <= 105
 1 <= n == grid[i].length <= 105
 2 <= m * n <= 105
 1 <= grid[i][j] <= 105
*/

bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    // Check horizontal cuts
    for(int i = 0; i < m-1; i++) {
        long long sum1 = 0, sum2 = 0;
        
        // Calculate sums for both sections
        for(int j = 0; j < n; j++) {
            for(int k = 0; k <= i; k++) {
                sum1 += grid[k][j];
            }
            for(int k = i+1; k < m; k++) {
                sum2 += grid[k][j];
            }
        }
        
        // Check if sums are equal or can be made equal by discounting one cell
        if(sum1 == sum2) return true;
        
        // Try discounting one cell from section 1
        for(int r = 0; r <= i; r++) {
            for(int c = 0; c < n; c++) {
                if(sum1 - grid[r][c] == sum2) {
                    // Check if remaining cells are connected
                    if(n == 1 || r == 0 || r == i) return true;
                }
            }
        }
        
        // Try discounting one cell from section 2 
        for(int r = i+1; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(sum1 == sum2 - grid[r][c]) {
                    // Check if remaining cells are connected
                    if(n == 1 || r == i+1 || r == m-1) return true;
                }
            }
        }
    }
    
    // Check vertical cuts
    for(int j = 0; j < n-1; j++) {
        long long sum1 = 0, sum2 = 0;
        
        // Calculate sums for both sections
        for(int i = 0; i < m; i++) {
            for(int k = 0; k <= j; k++) {
                sum1 += grid[i][k];
            }
            for(int k = j+1; k < n; k++) {
                sum2 += grid[i][k];
            }
        }
        
        // Check if sums are equal or can be made equal by discounting one cell
        if(sum1 == sum2) return true;
        
        // Try discounting one cell from section 1
        for(int r = 0; r < m; r++) {
            for(int c = 0; c <= j; c++) {
                if(sum1 - grid[r][c] == sum2) {
                    // Check if remaining cells are connected
                    if(m == 1 || c == 0 || c == j) return true;
                }
            }
        }
        
        // Try discounting one cell from section 2
        for(int r = 0; r < m; r++) {
            for(int c = j+1; c < n; c++) {
                if(sum1 == sum2 - grid[r][c]) {
                    // Check if remaining cells are connected
                    if(m == 1 || c == j+1 || c == n-1) return true;
                }
            }
        }
    }
    
    return false;
}            

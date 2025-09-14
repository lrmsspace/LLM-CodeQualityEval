/*
 You are given a 2D matrix grid consisting of positive integers.
 You have to select one or more cells from the matrix such that the following conditions are satisfied:
 No two selected cells are in the same row of the matrix.
 The values in the set of selected cells are unique.
 Your score will be the sum of the values of the selected cells.
 Return the maximum score you can achieve.
 Example 1:
 Input: grid = [[1,2,3],[4,3,2],[1,1,1]]
 Output: 8
 Explanation:
 We can select the cells with values 1, 3, and 4 that are colored above.
 Example 2:
 Input: grid = [[8,7,6],[8,3,2]]
 Output: 15
 Explanation:
 We can select the cells with values 7 and 8 that are colored above.
 Constraints:
 1 <= grid.length, grid[i].length <= 10
 1 <= grid[i][j] <= 100
*/

class Solution {
    public int maxScore(List<List<Integer>> grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid.get(0).size();
        int[][] dp = new int[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = grid.get(i).get(j);
                }
                else if(i == 0) {
                    dp[i][j] = Math.max(dp[i][j-1], grid.get(i).get(j));
                }
                else if(j == 0) {
                    dp[i][j] = Math.max(dp[i-1][j], grid.get(i).get(j));
                }
                else {
                    dp[i][j] = Math.max(Math.max(dp[i-1][j], dp[i][j-1]), grid.get(i).get(j));
                }
            }
        }
        return dp[n-1][m-1];
        
    }
}
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
        int m = grid.size(), n = grid.get(0).size(), res = 0;
        int[] dp = new int[1 << n];
        for (int i = 0; i < m; i++) {
            int mask = 0;
            for (int j = 0; j < n; j++)
                if (grid.get(i).get(j) != 0)
                    mask |= 1 << j;
            for (int j = dp.length - 1; j >= 0; j--) {
                if ((j & mask) == 0)
                    dp[j | mask] = Math.max(dp[j | mask], dp[j] + grid.get(i).stream().filter(x -> x != 0).mapToInt(Integer::intValue).sum());
            }
        }
        for (int i : dp)
            res = Math.max(res, i);
        return res;
    }
}
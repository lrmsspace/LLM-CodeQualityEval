/*
 You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:
 Each of the two resulting sections formed by the cut is non-empty.
 The sum of the elements in both sections is equal.
 Return true if such a partition exists; otherwise return false.
 Example 1:
 Input: grid = [[1,4],[2,3]]
 Output: true
 Explanation:
 A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.
 Example 2:
 Input: grid = [[1,3],[2,4]]
 Output: false
 Explanation:
 No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is false.
 Constraints:
 1 <= m == grid.length <= 105
 1 <= n == grid[i].length <= 105
 2 <= m * n <= 105
 1 <= grid[i][j] <= 105
*/

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += grid[i][j];
            }
        }
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<int> rowSums(m, 0), colSums(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSums[i] += grid[i][j];
                colSums[j] += grid[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            if (rowSums[i] == target) return true;
        }
        for (int i = 0; i < n; ++i) {
            if (colSums[i] == target) return true;
        }
        return false;
    }
};
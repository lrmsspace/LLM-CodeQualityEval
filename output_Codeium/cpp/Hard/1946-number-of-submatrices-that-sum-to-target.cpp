/**https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/ */
//Given a matrix and a target, return the number of non-empty submatrices that sum to target.
//A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
//Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.
// 
//Example 1:
//Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
//Output: 4
//Explanation: The four 1x1 submatrices that only contain 0.
//Example 2:
//Input: matrix = [[1,-1],[-1,1]], target = 0
//Output: 5
//Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
//Example 3:
//Input: matrix = [[904]], target = 0
//Output: 0
// 
//Constraints:
//	1 <= matrix.length <= 100
//	1 <= matrix[0].length <= 100
//	-1000 <= matrix[i][j] <= 1000
//	-10^8 <= target <= 10^8
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int result = 0;

        // Prefix sum for each row
        for (int i = 0; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        // Iterate over all pairs of columns
        for (int start_col = 0; start_col < cols; ++start_col) {
            for (int end_col = start_col; end_col < cols; ++end_col) {
                unordered_map<int, int> counter;
                counter[0] = 1;
                int curr_sum = 0;

                // Calculate submatrix sum for rows between start_col and end_col
                for (int row = 0; row < rows; ++row) {
                    curr_sum += matrix[row][end_col] - (start_col > 0 ? matrix[row][start_col - 1] : 0);
                    result += counter[curr_sum - target];
                    counter[curr_sum]++;
                }
            }
        }

        return result;

    }
};
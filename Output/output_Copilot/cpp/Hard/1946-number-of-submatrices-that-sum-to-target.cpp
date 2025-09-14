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
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum[i][j] = matrix[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
        int res = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= i; ++k) {
                    for (int l = 1; l <= j; ++l) {
                        int cur = sum[i][j] - sum[k - 1][j] - sum[i][l - 1] + sum[k - 1][l - 1];
                        if (cur == target) {
                            ++res;
                        }
                    }
                }
            }
        }
        return res;        
    }
};
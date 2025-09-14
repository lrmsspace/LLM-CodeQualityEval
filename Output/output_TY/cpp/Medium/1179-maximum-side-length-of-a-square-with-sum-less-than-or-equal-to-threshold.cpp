/**https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/ */
//Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.
// 
//Example 1:
//Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
//Output: 2
//Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
//Example 2:
//Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
//Output: 0
// 
//Constraints:
//	m == mat.length
//	n == mat[i].length
//	1 <= m, n <= 300
//	0 <= mat[i][j] <= 104
//	0 <= threshold <= 105
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> preSum(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        int ans = 0;
        for (int i = 1; i <= m;i++) {
            for (int j = 1; j <= n; j++) {
                int l = 0, r = min(m - i + 1, n - j + 1);
                while (l < r) {
                    int mid = l + (r - l + 1) / 2;
                    if (preSum[i + mid - 1][j + mid - 1] - preSum[i - 1][j - 1] - preSum[i + mid - 1][j - 1] - preSum[i - 1][j + mid - 1] <= threshold) {
                        l = mid;
                    }
                    else {
                        r = mid- 1;
                    }
                }
            }
        }
        return ans;
    }
};
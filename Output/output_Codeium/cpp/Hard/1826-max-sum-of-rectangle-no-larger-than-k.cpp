/**https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/ */
//Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
//It is guaranteed that there will be a rectangle with a sum no larger than k.
// 
//Example 1:
//Input: matrix = [[1,0,1],[0,-2,3]], k = 2
//Output: 2
//Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).
//Example 2:
//Input: matrix = [[2,2,-1]], k = 3
//Output: 3
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m, n <= 100
//	-100 <= matrix[i][j] <= 100
//	-105 <= k <= 105
// 
//Follow up: What if the number of rows is much larger than the number of columns?
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> preSum(n + 1, 0);
        int res = INT_MIN;
        for (int i = 0; i < m; ++i) {
            vector<int> curSum(n + 1, 0);
            for (int j = i; j < m; ++j) {
                for (int c = 0; c < n; ++c) {
                    curSum[c + 1] = curSum[c] + matrix[j][c];
                }
                set<int> s;
                s.insert(0);
                int cur = 0;
                for (int c = 0; c <= n; ++c) {
                    cur += curSum[c];
                    auto it = s.lower_bound(cur - k);
                    if (it != s.end()) res = max(res, cur - *it);
                    s.insert(cur);
                }
            }
        }
        return res;
    }
};
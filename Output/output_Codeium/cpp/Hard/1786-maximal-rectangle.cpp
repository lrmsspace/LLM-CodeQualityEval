/**https://leetcode.com/problems/maximal-rectangle/ */
//Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// 
//Example 1:
//Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//Output: 6
//Explanation: The maximal rectangle is shown in the above picture.
//Example 2:
//Input: matrix = [["0"]]
//Output: 0
//Example 3:
//Input: matrix = [["1"]]
//Output: 1
// 
//Constraints:
//	rows == matrix.length
//	cols == matrix[i].length
//	1 <= row, cols <= 200
//	matrix[i][j] is '0' or '1'.
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0);
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            stack<int> s;
            for (int j = 0; j <= n; ++j) {
                while (!s.empty() && (j == n || height[s.top()] >= height[j])) {
                    int cur = s.top(); s.pop();
                    int w = s.empty() ? j : j - s.top() - 1;
                    res = max(res, height[cur] * w);
                }
                s.push(j);
            }
        }
        return res;
    }
};
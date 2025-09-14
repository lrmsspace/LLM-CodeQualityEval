/**https://leetcode.com/problems/largest-submatrix-with-rearrangements/ */
//You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
//Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.
// 
//Example 1:
//Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
//Output: 4
//Explanation: You can rearrange the columns as shown above.
//The largest submatrix of 1s, in bold, has an area of 4.
//Example 2:
//Input: matrix = [[1,0,1,0,1]]
//Output: 3
//Explanation: You can rearrange the columns as shown above.
//The largest submatrix of 1s, in bold, has an area of 3.
//Example 3:
//Input: matrix = [[1,1,0],[1,0,1]]
//Output: 2
//Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
// 
//Constraints:
//	m == matrix.length
//	n == matrix[i].length
//	1 <= m * n <= 105
//	matrix[i][j] is either 0 or 1.
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0), left(n, 0), right(n, n);
        int maxArea = 0;
        
        for (int i = 0; i < m; ++i) {
            int curLeft = 0, curRight = n - 1;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
                while (curLeft < j && height[curLeft] >= height[j]) {
                    curLeft++;
                }
                left[j] = curLeft;
                while (curRight > j && height[curRight] >= height[j]) {
                    curRight--;
                }
                right[j] = curRight;
            }
            
            for (int j = 0; j < n; ++j) {
                maxArea = max(maxArea, height[j] * (right[j] - left[j] + 1));
            }
        }

        return maxArea;
        
    }
};
/**https://leetcode.com/problems/spiral-matrix-ii/ */
//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
// 
//Example 1:
//Input: n = 3
//Output: [[1,2,3],[8,9,4],[7,6,5]]
//Example 2:
//Input: n = 1
//Output: [[1]]
// 
//Constraints:
//	1 <= n <= 20
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int num = 1;
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        while (true) {
            for (int i = left; i <= right; i++) matrix[top][i] = num++;
            if (++top > bottom) break;
            for (int i = top; i <= bottom; i++) matrix[i][right] = num++;
            if (--right < left) break;
            for (int i = right; i >= left; i--) matrix[bottom][i] = num++;
            if (--bottom < top) break;
            for (int i = bottom; i >= top; i--) matrix[i][left] = num++;
            if (++left > right) break;
        }
        return matrix;    
    }
};
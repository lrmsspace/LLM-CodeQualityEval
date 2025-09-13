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
        vector<vector<int>> result(n, vector<int>(n));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int num = 1;
        
        while (left <= right && top <= bottom) {
            // Traverse right
            for (int i = left; i <= right; i++)
                result[top][i] = num++;
            
            // Traverse down
            for (int i = top + 1; i <= bottom; i++)
                result[i][right] = num++;
            
            // Traverse left
            if (left < right) {
                for (int i = right - 1; i >= left; i--)
                    result[bottom][i] = num++;
            }
            
            // Traverse up
            if (top < bottom) {
                for (int i = bottom - 1; i > top; i--)
                    result[i][left] = num++;
            }
            
            left++; right--; top++; bottom--;
        }
        
        return result;
        
    }
};
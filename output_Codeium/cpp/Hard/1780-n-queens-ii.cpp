/**https://leetcode.com/problems/n-queens-ii/ */
//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//Given an integer n, return the number of distinct solutions to the n-queens puzzle.
// 
//Example 1:
//Input: n = 4
//Output: 2
//Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
//Example 2:
//Input: n = 1
//Output: 1
// 
//Constraints:
//	1 <= n <= 9
class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> cols(n, false), d1(2 * n - 1, false), d2(2 * n - 1, false);
        
        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                count++;
                return;
            }
            for (int col = 0; col < n; col++) {
                if (cols[col] || d1[row - col + n - 1] || d2[row + col]) continue;
                cols[col] = d1[row - col + n - 1] = d2[row + col] = true;
                backtrack(row + 1);
                cols[col] = d1[row - col + n - 1] = d2[row + col] = false;
            }
        };
        
        backtrack(0);
        return count;

    }
};
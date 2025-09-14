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
    public int totalNQueens(int n) {
        int[] cols = new int[n];
        int[] ld = new int[2 * n - 1];
        int[] rd = new int[2 * n - 1];
        return backtrack(n, 0, cols, ld, rd);   
    }
}
/**https://leetcode.com/problems/n-queens/ */
//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
//Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
// 
//Example 1:
//Input: n = 4
//Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
//Example 2:
//Input: n = 1
//Output: [["Q"]]
// 
//Constraints:
//	1 <= n <= 9
class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), 0, new boolean[n], new boolean[2*n-1], new boolean[n]);
        return result;
    }

    public void backtrack(List<List<String>> result, List<String> currentList, int row, boolean[] cols, boolean[] mainDiagonal, boolean[] antiDiagonal) {
        if (row == currentList.size()) {
            result.add(new ArrayList<>(currentList));
            return;
        }
        for (int i = 0; i < cols.length; i++) {
            if (!cols[i] && !mainDiagonal[row + i] && !antiDiagonal[row - i + cols.length - 1]) {
                cols[i] = true;
                mainDiagonal[row + i] = true;
                antiDiagonal[row - i + cols.length - 1] = true;
                currentList.add(placeQueen(i, cols.length));
                backtrack(result, currentList, row + 1, cols, mainDiagonal, antiDiagonal);
                currentList.remove(currentList.size() - 1);
                antiDiagonal[row - i + cols.length - 1] = false;
                mainDiagonal[row + i] = false;
                cols[i] = false;
            }
        }
    }
}
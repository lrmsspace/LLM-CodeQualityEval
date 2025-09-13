/**https://leetcode.com/problems/queens-that-can-attack-the-king/ */
//On a 0-indexed 8 x 8 chessboard, there can be multiple black queens and one white king.
//You are given a 2D integer array queens where queens[i] = [xQueeni, yQueeni] represents the position of the ith black queen on the chessboard. You are also given an integer array king of length 2 where king = [xKing, yKing] represents the position of the white king.
//Return the coordinates of the black queens that can directly attack the king. You may return the answer in any order.
// 
//Example 1:
//Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
//Output: [[0,1],[1,0],[3,3]]
//Explanation: The diagram above shows the three queens that can directly attack the king and the three queens that cannot attack the king (i.e., marked with red dashes).
//Example 2:
//Input: queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
//Output: [[2,2],[3,4],[4,4]]
//Explanation: The diagram above shows the three queens that can directly attack the king and the three queens that cannot attack the king (i.e., marked with red dashes).
// 
//Constraints:
//	1 <= queens.length < 64
//	queens[i].length == king.length == 2
//	0 <= xQueeni, yQueeni, xKing, yKing < 8
//	All the given positions are unique.
class Solution {
    public List<List<Integer>> queensAttacktheKing(int[][] queens, int[] king) {
        List<List<Integer>> result = new ArrayList<>();
        boolean[][] board = new boolean[8][8];
        for (int[] queen : queens) {
            board[queen[0]][queen[1]] = true;
        }
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                for (int k = 1; k < 8; k++) {
                    int x = king[0] + i * k;
                    int y = king[1] + j * k;
                    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
                        break;
                    }
                    if (board[x][y]) {
                        result.add(Arrays.asList(x, y));
                        break;
                    }
                }
            }
        }
        return result;        
    }
}
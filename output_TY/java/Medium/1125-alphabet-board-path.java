/**https://leetcode.com/problems/alphabet-board-path/ */
//On an alphabet board, we start at position (0, 0), corresponding to character board[0][0].
//Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below.
//We may make the following moves:
//	'U' moves our position up one row, if the position exists on the board;
//	'D' moves our position down one row, if the position exists on the board;
//	'L' moves our position left one column, if the position exists on the board;
//	'R' moves our position right one column, if the position exists on the board;
//	'!' adds the character board[r][c] at our current position (r, c) to the answer.
//(Here, the only positions that exist on the board are positions with letters on them.)
//Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so.
// 
//Example 1:
//Input: target = "leet"
//Output: "DDR!UURRR!!DDD!"
//Example 2:
//Input: target = "code"
//Output: "RR!DDRR!UUL!R!"
// 
//Constraints:
//	1 <= target.length <= 100
//	target consists only of English lowercase letters.
class Solution {
    public String alphabetBoardPath(String target) {
        StringBuilder sb = new StringBuilder();
        int curr = 0;
        for (int i = 0; i < target.length(); i++) {
            int next = target.charAt(i) - 'a';
            int row = next / 5;
            int col = next % 5;
            while (curr != next) {
                if (curr < next) {
                    if (curr % 5 == 4) {
                        sb.append("D");
                        curr += 5;
                    } else {
                        sb.append("R");
                        curr++;
                    }
                } else {
                    if (curr % 5 == 0){
                        sb.append("L");
                        curr--;
                    } else {
                        sb.append("U");
                        curr -= 5;
                    }
                }
            }
        }
        sb.append("!");
        return sb.toString();
    }
}
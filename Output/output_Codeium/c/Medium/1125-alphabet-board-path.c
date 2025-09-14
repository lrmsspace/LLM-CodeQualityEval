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


char * alphabetBoardPath(char * target){

    int len = strlen(target);
    char *res = (char*)malloc(len * 5 * sizeof(char));
    int idx = 0;
    int r = 0, c = 0;
    for (int i = 0; i < len; i++) {
        int nr = (target[i] - 'a') / 5;
        int nc = (target[i] - 'a') % 5;
        while (r != nr) {
            if (r < nr) {
                res[idx++] = 'D';
                r++;
            } else {
                res[idx++] = 'U';
                r--;
            }
        }
        while (c != nc) {
            if (c < nc) {
                res[idx++] = 'R';
                c++;
            } else {
                res[idx++] = 'L';
                c--;
            }
        }
        res[idx++] = '!';
    }
    res[idx] = '\0';
    return res;
}

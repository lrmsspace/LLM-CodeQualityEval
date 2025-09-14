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
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int len = strlen(target);
    char *ret = (char *)malloc(sizeof(char) * (len * 6 + 1));
    ret[0] = '\0';
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    for(i = 0; i < len; i++) {
        x2 = (target[i] - 'a') / 5;
        y2 = (target[i] - 'a') % 5;
        if(x1 == x2 && y1 == y2) {
            strcat(ret, "!");
        } else {
            while(x1 > x2) {
                strcat(ret, "U");
                x1--;
            }
            while(y1 > y2) {
                strcat(ret, "L");
                y1--;
            }
            while(x1 < x2) {
                strcat(ret, "D");
                x1++;
            }
            while(y1 < y2) {
                strcat(ret, "R");
                y1++;
            }
            strcat(ret, "!");
        }
    }
    return ret;
}
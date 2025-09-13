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
    static const char board[6][5] = {
        {'a', 'b', 'c', 'd', 'e'},
        {'f', 'g', 'h', 'i', 'j'},
        {'k', 'l','m', 'n', 'o'},
        {'p', 'q', 'r','s', 't'},
        {'u', 'v', 'w', 'x', 'y'},
        {'z', 0, 0, 0, 0}
    };
    static const int dx[5] = {0, 0, -1, 1, 0};
    static const int dy[5] = {-1, 1, 0, 0, 0};
    static int x = 0, y = 0;
    static char *res = malloc(sizeof(char) * (strlen(target) + 1));
    res[0] = 0;
    int len = 0;
    for (int i = 0; target[i]; ++i) {
        int nx = -1, ny = -1;
        for (int j = 0; board[j][5]; ++j) {
            if (board[j][0] == target[i]) {
                nx = j;
                ny = board[j] == target[i]? 4 : 0;
                break;
            }
        }
        if (nx == -1 || ny == -1) {
            free(res);
            return NULL;
        }
        int dist = abs(x - nx) + abs(y - ny);
        for (int j = 0; j < dist; ++j) {
            int tx = x + dx[y == 4? 0 : (y == 0? 1 : y > ny? -1 : 1)];
            int ty = y + dy[y == 4? 0 : (y == 0? -1 : y > ny? 1 : 0)];
            res[len++] = (y == 4? 'U' : 'D') * abs(x - tx) + (x == 4? 'R' : 'L') * abs(y - ty);
            x = tx;
            y = ty;
        }
        res[len++] = '!';

        res[len] = 0;
        x = nx;
        y = ny;
        // printf("%s\n", res);
    }
    return res;
}
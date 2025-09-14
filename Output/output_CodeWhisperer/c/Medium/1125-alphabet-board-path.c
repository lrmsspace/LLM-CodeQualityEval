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


char * alphabetBoardPath(char * target)
{
    int i = 0, j = 0;
    int x = 0, y = 0;
    char *result = (char *)malloc(sizeof(char) * 1000);
    int resultIndex = 0;
    while (target[i] != '\0')
    {
        x = (target[i] - 'a') / 5;
        y = (target[i] - 'a') % 5;
        while (x < j)
        {
            result[resultIndex++] = 'U';
            j--;
        }
        while (x > j)
        {
            result[resultIndex++] = 'D';
            j++;
        }
        while (y < i)
        {
            result[resultIndex++] = 'L';
            i--;
        }
        while (y > i)
        {
            result[resultIndex++] = 'R';
            i++;
        }
        result[resultIndex++] = '!';
        i = 0;
        j = 0;
        target++;
    }
    result[resultIndex] = '\0';
    return result;
}
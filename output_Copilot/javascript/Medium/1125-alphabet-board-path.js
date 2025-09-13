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
/**
 * @param {string} target
 * @return {string}
 */
var alphabetBoardPath = function(target) {
    const board = "abcdefghijklmnopqrstuvwxyz";
    const pos = {};
    for (let i = 0; i < 26; i++) {
        pos[board[i]] = [Math.floor(i / 5), i % 5];
    }
    let result = "";
    let [x, y] = [0, 0];
    for (const char of target) {
        const [nx, ny] = pos[char];
        if (nx < x) result += "U".repeat(x - nx);
        if (ny < y) result += "L".repeat(y - ny);
        if (nx > x) result += "D".repeat(nx - x);
        if (ny > y) result += "R".repeat(ny - y);
        result += "!";
        [x, y] = [nx, ny];
    }
    return result;    
};
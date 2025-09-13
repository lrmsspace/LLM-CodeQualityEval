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
    var result = [];
    var start = [0, 0];
    var end = [0, 0];
    for (var i = 0; i < target.length; i++) {
        end = getPosition(target[i]);
        result.push(getMove(start, end));
        start = end;
    }
    return result.join('');
};

function getPosition(letter) {
    var row = Math.floor((letter.charCodeAt(0) - 97) / 5);
    var col = (letter.charCodeAt(0) - 97) % 5;
    return [row, col];
}

function getMove(start, end) {
    var result = [];
    while (start[0] !== end[0] || start[1] !== end[1]) {
        if (start[0] < end[0]) {
            result.push('D');
            start[0]++;
        } else if (start[0] > end[0]) {
            result.push('U');
            start[0]--;
        }
        if (start[1] < end[1]) {
            result.push('R');
            start[1]++;
        } else if (start[1] > end[1]) {
            result.push('L');
            start[1]--;
        }
    }
    result.push('!');
}
};
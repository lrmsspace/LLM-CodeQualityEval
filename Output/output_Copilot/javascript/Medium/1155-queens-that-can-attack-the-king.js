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
/**
 * @param {number[][]} queens
 * @param {number[]} king
 * @return {number[][]}
 */
var queensAttacktheKing = function(queens, king) {
    const result = [];
    const directions = [
        [-1, 0], // up
        [1, 0], // down
        [0, -1], // left
        [0, 1], // right
        [-1, -1], // up-left
        [-1, 1], // up-right
        [1, -1], // down-left
        [1, 1] // down-right
    ];

    const queensSet = new Set(queens.map(q => q.join(',')));

    for (const [dx, dy] of directions) {
        let x = king[0];
        let y = king[1];

        while (true) {
            x += dx;
            y += dy;

            if (x < 0 || x >= 8 || y < 0 || y >= 8) break;
            if (queensSet.has(`${x},${y}`)) {
                result.push([x, y]);
                break;
            }
        }
    }

    return result;    
};
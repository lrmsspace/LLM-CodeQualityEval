/**https://leetcode.com/problems/sliding-puzzle/ */
//On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
//The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
//Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.
// 
//Example 1:
//Input: board = [[1,2,3],[4,0,5]]
//Output: 1
//Explanation: Swap the 0 and the 5 in one move.
//Example 2:
//Input: board = [[1,2,3],[5,4,0]]
//Output: -1
//Explanation: No number of moves will make the board solved.
//Example 3:
//Input: board = [[4,1,2],[5,0,3]]
//Output: 5
//Explanation: 5 is the smallest number of moves that solves the board.
//An example path:
//After move 0: [[4,1,2],[5,0,3]]
//After move 1: [[4,1,2],[0,5,3]]
//After move 2: [[0,1,2],[4,5,3]]
//After move 3: [[1,0,2],[4,5,3]]
//After move 4: [[1,2,0],[4,5,3]]
//After move 5: [[1,2,3],[4,5,0]]
// 
//Constraints:
//	board.length == 2
//	board[i].length == 3
//	0 <= board[i][j] <= 5
//	Each value board[i][j] is unique.
/**
 * @param {number[][]} board
 * @return {number}
 */
var slidingPuzzle = function(board) {
    const target = [1,2,3,4,5,0];
    const moves = [[0,1], [0,-1], [1,0], [-1,0]];
    const visited = new Set();
    const queue = [[board.flat(), 0]];
    
    while (queue.length) {
        const [current, steps] = queue.shift();
        
        if (current.join('') === target.join('')) {
            return steps;
        }
        
        visited.add(current.join(''));
        
        for (const [dx, dy] of moves) {
            const [x, y] = current.findIndex((num) => num === 0).split(',').map(Number);
            const nx = x + dx;
            const ny = y + dy;
            
            if (nx >= 0 && nx < board.length && ny >= 0 && ny < board[0].length) {
                const next = [...current];
                [next[x * 3 + y], next[nx * 3 + ny]] = [next[nx * 3 + ny], next[x * 3 + y]];
                
                if (!visited.has(next.join(''))) {
                    queue.push([next, steps + 1]);
                }
            }
        }

    }
    
    return -1;
    
};
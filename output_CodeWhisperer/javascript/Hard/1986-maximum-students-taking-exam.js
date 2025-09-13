/**https://leetcode.com/problems/maximum-students-taking-exam/ */
//Given a m * n matrix seats  that represent seats distributions in a classroom. If a seat is broken, it is denoted by '#' character otherwise it is denoted by a '.' character.
//Students can see the answers of those sitting next to the left, right, upper left and upper right, but he cannot see the answers of the student sitting directly in front or behind him. Return the maximum number of students that can take the exam together without any cheating being possible.
//Students must be placed in seats in good condition.
// 
//Example 1:
//Input: seats = [["#",".","#","#",".","#"],
//                [".","#","#","#","#","."],
//                ["#",".","#","#",".","#"]]
//Output: 4
//Explanation: Teacher can place 4 students in available seats so they don't cheat on the exam. 
//Example 2:
//Input: seats = [[".","#"],
//                ["#","#"],
//                ["#","."],
//                ["#","#"],
//                [".","#"]]
//Output: 3
//Explanation: Place all students in available seats. 
//Example 3:
//Input: seats = [["#",".",".",".","#"],
//                [".","#",".","#","."],
//                [".",".","#",".","."],
//                [".","#",".","#","."],
//                ["#",".",".",".","#"]]
//Output: 10
//Explanation: Place students in available seats in column 1, 3 and 5.
// 
//Constraints:
//	seats contains only characters '.' and'#'.
//	m == seats.length
//	n == seats[i].length
//	1 <= m <= 8
//	1 <= n <= 8
/**
 * @param {character[][]} seats
 * @return {number}
 */
var maxStudents = function(seats) {
    const m = seats.length;
    const n = seats[0].length;
    const isValid = (row, col) => {
        return row >= 0 && row < m && col >= 0 && col < n;
    }
    const memo = new Map();
    const dfs = (row, col, prevRow) => {
        if (row === m) return 0;
        const key = `${row}-${col}-${prevRow}`;
        if (memo.has(key)) return memo.get(key);
        let max = 0;
        for (let i = 0; i < n; i++) {
            if (seats[row][i] === '.' && !(i > 0 && seats[row][i - 1] === '1' && prevRow & (1 << (i - 1))) && !(i < n - 1 && seats[row][i + 1] === '1' && prevRow & (1 << (i + 1)))) {
                const currRow = prevRow | (1 << i);
                max = Math.max(max, (i & 1 ? 0 : 1) + dfs(row + 1, 0, currRow >> 1));
            }
        }
        memo.set(key, max);
        return max;
    }
    return dfs(0, 0, 0);
};
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
    const m = seats.length, n = seats[0].length;
    const dp = new Array(1 << n).fill(0);
    for (let i = 0; i < m; i++) {
        const nextDp = new Array(1 << n).fill(0);
        for (let mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] === 0) continue;
            for (let j = 0; j < (1 << n); j++) {
                if ((j & mask) !== 0 || (j & (j >> 1)) !== 0 || (j & (j << 1)) !== 0) continue;
                let count = 0;
                for (let k = 0; k < n; k++) {
                    if ((j & (1 << k)) !== 0 && seats[i][k] === '.') count++;
                }
                nextDp[j] = Math.max(nextDp[j], dp[mask] + count);
            }
        }
        dp.length = nextDp.length;
        dp.splice(0, dp.length, ...nextDp);
    }
    return Math.max(...dp);    
};
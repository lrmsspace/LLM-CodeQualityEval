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
int maxStudents(char** seats, int seatsSize, int* seatsColSize) {
    int m = seatsSize;
    int n = seatsColSize[0];
    int dp[m][1 << n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (1 << n); j++) {
            int valid = 1;
            int num = 0;
            for (int k = 0; k < n; k++) {
                if ((j & (1 << k)) != 0) {
                    num++;
                    if (seats[i][k] == '#') {
                        valid = 0;
                    }
                    if (k > 0 && (j & (1 << (k - 1))) != 0) {
                        valid = 0;
                    }
                    if (k < n - 1 && (j & (1 << (k + 1))) != 0) {
                        valid = 0;
                    }
                    if (i > 0 && k > 0 && (dp[i - 1][j >> 1] & (1 << (k - 1))) != 0) {
                        valid = 0;
                    }
                    if (i > 0 && k < n - 1 && (dp[i - 1][j >> 1] & (1 << (k + 1))) != 0) {
                        valid = 0;
                    }
                }
            }
            if (valid) {
                dp[i][j] = num;
                for (int k = 0; k < (1 << n); k++) {
                    if ((k & j) == 0) {
                        dp[i][j] = fmax(dp[i][j], dp[i - 1][k] + num);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        ans = fmax(ans, dp[m - 1][i]);
    }
    return ans;
}
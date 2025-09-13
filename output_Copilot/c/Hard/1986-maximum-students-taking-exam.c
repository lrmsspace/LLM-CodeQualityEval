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
    int m = seatsSize, n = seatsColSize[0];
    int* dp = (int*)malloc((m + 1) * (1 << n) * sizeof(int));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i * (1 << n) + j] = -1;
        }
    }
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < (1 << n); j++) {
            if (dp[(i - 1) * (1 << n) + j] == -1) continue;
            for (int k = 0; k < (1 << n); k++) {
                if ((k & (k >> 1)) == 0 && (k & (j >> 1)) == 0 && (k & (j << 1)) == 0) {
                    int count = 0;
                    for (int l = 0; l < n; l++) {
                        if ((k & (1 << l)) != 0 && seats[i - 1][l] == '.') {
                            count++;
                        }
                    }
                    dp[i * (1 << n) + k] = fmax(dp[i * (1 << n) + k], dp[(i - 1) * (1 << n) + j] + count);
                }
            }
        }
    }
    int result = 0;
    for (int i = 0; i < (1 << n); i++) {
        result = fmax(result, dp[m * (1 << n) + i]);
    }
    free(dp);
    return result;    
}
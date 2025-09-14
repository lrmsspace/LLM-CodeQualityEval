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
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    
    for (int j = 0; j < n; j++) {
        if (seats[0][j] == '.') {
            dp[0][j] = 1;
        }
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (seats[i][j] == '.') {
                dp[i][j] = dp[i-1][j];
                if (j > 0 && seats[i][j-1] == '.') {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                }
                if (j < n-1 && seats[i][j+1] == '.') {
                    dp[i][j] = max(dp[i][j], dp[i-1][j+1] + 1);
                }
            }
        }

    }
    
    int max_students = 0;
    for (int i = 0; i < m; i++) {
        max_students = max(max_students, dp[i][n-1]);
    }
    
    return max_students;
    
}
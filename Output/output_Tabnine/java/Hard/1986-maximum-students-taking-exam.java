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
class Solution {
    public int maxStudents(char[][] seats) {
        int m = seats.length, n = seats[0].length;
        int[][] dp = new int[m][n];
        int[] left = new int[m], right = new int[m];
        
        // Initialize left and right arrays
        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (seats[i][j] == '#') {
                    count = 0;
                } else {
                    count++;
                    left[i] = Math.max(left[i], count);
                }
            }
            count = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (seats[i][j] == '#') {
                    count = 0;
                } else {
                    count++;
                    right[i] = Math.max(right[i], count);
                }
            }
        }
        
        // Fill dp array
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (seats[i][j] == '#') {
                    dp[i][j] = 0;
                } else {
                    int maxCount = 0;
                    for (int k = 0; k < i; k++) {
                        maxCount = Math.max(maxCount, dp[k][j - 1]);
                    }
                    for (int k = i + 1; k < m; k++) {
                        maxCount = Math.max(maxCount, dp[k][j - 1]);
                    }
                    dp[i][j] = left[i] + right[i] - maxCount + 1;
                }
            }
        }
        
        // Return the maximum number of students that can take the exam together
        int maxStudents = 0;
        for (int i = 0; i < m; i++) {
            maxStudents = Math.max(maxStudents, dp[i][n - 1]);
        }
        return maxStudents;
        
    }
}
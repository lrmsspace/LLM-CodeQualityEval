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
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        vector<int> dp(1 << n, 0);
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        vector<int> diag(2 * m - 1, 0);
        vector<int> anti_diag(2 * m - 1, 0);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (seats[i][j] == '.') {
                    row[i] |= 1 << j;
                    col[j] |= 1 << i;
                    diag[i - j + m - 1] |= 1 << i;
                    anti_diag[i + j] |= 1 << i;
                }
            }
        }
        
        for (int mask = 0; mask < (1 << n); ++mask) {
            int count = __builtin_popcount(mask);
            for (int i = 0; i < m; ++i) {
                if (row[i] & mask && col[i] & mask && diag[i - i + m - 1] & mask && anti_diag[i + i] & mask) {
                    dp[mask] = max(dp[mask], dp[mask ^ (1 << i)] + count);
                }
            }
        }
        
        return dp[(1 << n) - 1];
    }
};
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
        vector<int> validRows;
        for (int i = 0; i < m; i++) {
            int mask = 0;
            for (int j = 0; j < n; j++) {
                mask = (mask << 1) + (seats[i][j] == '.' ? 1 : 0);
            }
            validRows.push_back(mask);
        }
        vector<vector<int>> dp(m, vector<int>(1 << n, -1));
        function<int(int, int)> dfs = [&](int i, int pre) {
            if (i == m) return 0;
            if (dp[i][pre] != -1) return dp[i][pre];
            int res = 0;
            for (int cur = 0; cur < (1 << n); cur++) {
                if ((cur & validRows[i]) == cur && !(cur & (cur >> 1)) && !(cur & (pre << 1)) && !(cur & (pre >> 1))) {
                    res = max(res, __builtin_popcount(cur) + dfs(i + 1, cur));
                }
            }
            return dp[i][pre] = res;
        };
        return dfs(0, 0);        
    }
};
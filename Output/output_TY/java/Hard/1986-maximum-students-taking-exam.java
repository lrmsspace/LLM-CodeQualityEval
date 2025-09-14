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
        int m=seats.length,n=seats[0].length;
        int[][] dp=new int[m][1<<n];
        for(int i=0;i<m;i++) for(int j=0;j<1<<n;j++) dp[i][j]=-1;
        return dfs(seats,0,0,dp);
    }
    public int dfs(char[][] seats,int row,int mask,int[][] dp){
        int m=seats.length,n=seats[0].length;
        if(row==m) return 0;
        if(dp[row][mask]!=-1) return dp[row][mask]; 
        int ans=0;
        for(int i=0;i<n;i++){
            if((mask&(1<<i))==0){
                int temp=0;
                for(int j=0;j<n;j++){
                    if((mask&(1<<j))>0){
                        if(seats[row][j]=='#') temp++;
                    }
                }
                ans=Math.max(ans,dfs(seats,row+1,mask|(1<<i),dp)+temp);
            }
        }
        return dp[row][mask]=ans;
    }
}
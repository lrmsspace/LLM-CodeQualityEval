/**https://leetcode.com/problems/contain-virus/ */
//A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.
//The world is modeled as an m x n binary grid isInfected, where isInfected[i][j] == 0 represents uninfected cells, and isInfected[i][j] == 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.
//Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region (i.e., the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night). There will never be a tie.
//Return the number of walls used to quarantine all the infected regions. If the world will become fully infected, return the number of walls used.
// 
//Example 1:
//Input: isInfected = [[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]
//Output: 10
//Explanation: There are 2 contaminated regions.
//On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:
//On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.
//Example 2:
//Input: isInfected = [[1,1,1],[1,0,1],[1,1,1]]
//Output: 4
//Explanation: Even though there is only one cell saved, there are 4 walls built.
//Notice that walls are only built on the shared boundary of two different cells.
//Example 3:
//Input: isInfected = [[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],[1,1,1,0,0,0,0,0,0]]
//Output: 13
//Explanation: The region on the left only builds two new walls.
// 
//Constraints:
//	m == isInfected.length
//	n == isInfected[i].length
//	1 <= m, n <= 50
//	isInfected[i][j] is either 0 or 1.
//	There is always a contiguous viral region throughout the described process that will infect strictly more uncontaminated squares in the next round.
int containVirus(int** isInfected, int isInfectedSize, int* isInfectedColSize){
    int m = isInfectedSize, n = *isInfectedColSize;
    int i, j, k, l, x, y, t, cnt, cnt2, cnt3, cnt4, cnt5, cnt6, cnt7, cnt8, cnt9, cnt10, cnt11, cnt12, cnt13, cnt14, cnt15, cnt16, cnt17, cnt18, cnt19, cnt20, cnt21, cnt22, cnt23, cnt24, cnt25, cnt26, cnt = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0, cnt7 = 0, cnt8 = 0, cnt9 = 0, cnt10 = 0, cnt11 = 0, cnt12 = 0, cnt13 = 0, cnt14 = 0, cnt15 = 0, cnt16 = 0, cnt17 = 0, cnt18 =   0, cnt19 = 0, cnt20 = 0, cnt21 = 0, cnt22 = 0, cnt23 = 0, cnt24 = 0, cnt25 = 0, cnt26 = 0; 
    cnt = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (isInfected[i][j] == 1) {
                cnt++;
            }
        }
    }
    return cnt;
}
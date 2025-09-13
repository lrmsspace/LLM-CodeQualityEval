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
class Solution {
    public int containVirus(int[][] isInfected) {
        int m = isInfected.length;
        int n = isInfected[0].length;
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int res = 0;
        while (true) {
            int[][] visited = new int[m][n];
            List<int[]> queue = new ArrayList<>();
            List<int[]> toWall = new ArrayList<>();
            boolean found = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (isInfected[i][j] == 1 && visited[i][j] == 0) {
                        if (!found) {
                            found = true;
                            queue.add(new int[]{i, j});
                        } else {
                            toWall.add(new int[]{i, j});
                        }
                        int[][] temp = new int[m][n];
                        int size = 1;
                        temp[i][j] = 1;
                        int[][] tempDirections = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                        while (!queue.isEmpty()) {
                            int[] cur = queue.remove(0);
                            for (int[] dir : tempDirections) {
                                int x = cur[0] + dir[0];
                                int y = cur[1] + dir[1];
                                if (x >= 0 && x < m && y >= 0 && y < n && isInfected[x][y] == 0 && temp[x][y] == 0) {
                                    temp[x][y] = 1;
                                    size++;
                                    queue.add(new int[]{x, y});
                                }
                            }
                        }
                        if (found) {
                            res += size;
                            for (int[] p : toWall) {
                                for (int[] dir : directions) {
                                    int x = p[0] + dir[0];
                                    int y = p[1] + dir[1];
                                    if (x >= 0 && x < m && y >= 0 && y < n && isInfected[x][y] == 0 && temp[x][y] == 0) {
                                        isInfected[x][y] = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (!found) break;
        }
        return res;
    }
}
/**https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/ */
//A storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.
//The game is represented by an m x n grid of characters grid where each element is a wall, floor, or box.
//Your task is to move the box 'B' to the target position 'T' under the following rules:
//	The character 'S' represents the player. The player can move up, down, left, right in grid if it is a floor (empty cell).
//	The character '.' represents the floor which means a free cell to walk.
//	The character '#' represents the wall which means an obstacle (impossible to walk there).
//	There is only one box 'B' and one target cell 'T' in the grid.
//	The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a push.
//	The player cannot walk through the box.
//Return the minimum number of pushes to move the box to the target. If there is no way to reach the target, return -1.
// 
//Example 1:
//Input: grid = [["#","#","#","#","#","#"],
//               ["#","T","#","#","#","#"],
//               ["#",".",".","B",".","#"],
//               ["#",".","#","#",".","#"],
//               ["#",".",".",".","S","#"],
//               ["#","#","#","#","#","#"]]
//Output: 3
//Explanation: We return only the number of times the box is pushed.
//Example 2:
//Input: grid = [["#","#","#","#","#","#"],
//               ["#","T","#","#","#","#"],
//               ["#",".",".","B",".","#"],
//               ["#","#","#","#",".","#"],
//               ["#",".",".",".","S","#"],
//               ["#","#","#","#","#","#"]]
//Output: -1
//Example 3:
//Input: grid = [["#","#","#","#","#","#"],
//               ["#","T",".",".","#","#"],
//               ["#",".","#","B",".","#"],
//               ["#",".",".",".",".","#"],
//               ["#",".",".",".","S","#"],
//               ["#","#","#","#","#","#"]]
//Output: 5
//Explanation: push the box down, left, left, up and up.
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 20
//	grid contains only characters '.', '#', 'S', 'T', or 'B'.
//	There is only one character 'S', 'B', and 'T' in the grid.
class Solution {
    public int minPushBox(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] start = new int[2];
        int[] target = new int[2];
        int[] box = new int[2];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    start[0] = i;
                    start[1] = j;
                } else if (grid[i][j] == 'T') {
                    target[0] = i;
                    target[1] = j;
                } else if (grid[i][j] == 'B') {
                    box[0] = i;
                    box[1] = j;
                }
            }
        }
        
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(start);     
        int minPushes = 0;
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            
            for (int i = 0; i < size; i++) {
                int[] curr = queue.poll();
                int currX = curr[0], currY = curr[1];
                
                if (currX == target[0] && currY == target[1]) {
                    return minPushes;
                }
    
                for (int[] dir : dirs) {
                    int newX = currX + dir[0], newY = currY + dir[1];
                    
                    if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] == '#') {
                        continue;
                    }
        
                    if (grid[newX][newY] == 'B') {
                        int boxX = box[0], boxY = box[1];
                        
                        while (boxX + dir[0] >= 0 && boxX + dir[0] < m && boxY + dir[1] >= 0 && boxY + dir[1] < n && grid[boxX + dir[0]][boxY + dir[1]]!= '#') {
                            boxX += dir[0];
                            boxY += dir[1];
                        }
            
                        if (grid[boxX][ boxY] == '.') {
                            grid[boxX][boxY] = 'B';
                            grid[newX][newY] = '.';
                            queue.offer(new int[]{boxX, boxY});
                            grid[newX][newY] = 'B';
                            grid[boxX][boxY] = '.';
                        }
                        continue;
                        
                    } else {
                        grid[newX][newY] = 'S';
                        grid[currX][currY] = '.';
                        queue.offer(new int[]{newX, newY});
                        grid[currX][currY] = 'S';
                    }
                    minPushes++;
                    break;
                    
                    if (i == size - 1) {
                        queue.poll();
                    }
                    
                    if (minPushes >= 100) {
                        return -1;
                    }
                    break;
                }
            }
        }
        return -1;

    }
}
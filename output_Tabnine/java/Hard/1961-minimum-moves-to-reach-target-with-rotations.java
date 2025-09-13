/**https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/ */
//In an n*n grid, there is a snake that spans 2 cells and starts moving from the top left corner at (0, 0) and (0, 1). The grid has empty cells represented by zeros and blocked cells represented by ones. The snake wants to reach the lower right corner at (n-1, n-2) and (n-1, n-1).
//In one move the snake can:
//	Move one cell to the right if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
//	Move down one cell if there are no blocked cells there. This move keeps the horizontal/vertical position of the snake as it is.
//	Rotate clockwise if it's in a horizontal position and the two cells under it are both empty. In that case the snake moves from (r, c) and (r, c+1) to (r, c) and (r+1, c).
//	
//	Rotate counterclockwise if it's in a vertical position and the two cells to its right are both empty. In that case the snake moves from (r, c) and (r+1, c) to (r, c) and (r, c+1).
//	
//Return the minimum number of moves to reach the target.
//If there is no way to reach the target, return -1.
// 
//Example 1:
//Input: grid = [[0,0,0,0,0,1],
//               [1,1,0,0,1,0],
//               [0,0,0,0,1,1],
//               [0,0,1,0,1,0],
//               [0,1,1,0,0,0],
//               [0,1,1,0,0,0]]
//Output: 11
//Explanation:
//One possible solution is [right, right, rotate clockwise, right, down, down, down, down, rotate counterclockwise, right, down].
//Example 2:
//Input: grid = [[0,0,1,1,1,1],
//               [0,0,0,0,1,1],
//               [1,1,0,0,0,1],
//               [1,1,1,0,0,1],
//               [1,1,1,0,0,1],
//               [1,1,1,0,0,0]]
//Output: 9
// 
//Constraints:
//	2 <= n <= 100
//	0 <= grid[i][j] <= 1
//	It is guaranteed that the snake starts at empty cells.
class Solution {
    public int minimumMoves(int[][] grid) {

        int n = grid.length;
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int[][] dist = new int[n][n];
        int[] start = null;
        int[] end = null;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (start == null) start = new int[]{i, j};
                    else if (end == null) end = new int[]{i, j};
                } else if (grid[i][j] == 2) {
                    end = new int[]{i, j};
                }
            }
        }
        int minMoves = Integer.MAX_VALUE;
        for (int d = 0; d < 4; d++) {
            int[][] dist2 = new int[n][n];
            Arrays.fill(dist2, Integer.MAX_VALUE);
            dist2[start[0]][start[1]] = 0;
            PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> dist2[a[0]][a[1]]));
            pq.offer(start);
            while (!pq.isEmpty()) {
                int[] curr = pq.poll();
                int x = curr[0], y = curr[1];
                if (x == end[0] && y == end[1]) {
                    minMoves = Math.min(minMoves, dist2[x][y]);
                    break;
                }
                for (int[] dir : directions) {
                    int nx = x + dir[0], ny = y + dir[1];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == 1) continue;
                    int newDist = dist2[x][y] + 1;
                    if (newDist < dist2[nx][ny]) {
                        dist2[nx][ny] = newDist;
                        pq.offer(new int[]{nx, ny});
                    }
                }
            }
            
            // rotate clockwise
            int[][] rotated = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    rotated[j][n - 1 - i] = dist2[i][j];
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    minMoves = Math.min(minMoves, rotated[i][j]);
                }
            }
        }
        return minMoves == Integer.MAX_VALUE? -1 : minMoves;
    }
}
/*
 You are given two positive integers xCorner and yCorner, and a 2D array circles, where circles[i] = [xi, yi, ri] denotes a circle with center at (xi, yi) and radius ri.
 There is a rectangle in the coordinate plane with its bottom left corner at the origin and top right corner at the coordinate (xCorner, yCorner). You need to check whether there is a path from the bottom left corner to the top right corner such that the entire path lies inside the rectangle, does not touch or lie inside any circle, and touches the rectangle only at the two corners.
 Return true if such a path exists, and false otherwise.
 Example 1:
 Input: xCorner = 3, yCorner = 4, circles = [[2,1,1]]
 Output: true
 Explanation:
 The black curve shows a possible path between (0, 0) and (3, 4).
 Example 2:
 Input: xCorner = 3, yCorner = 3, circles = [[1,1,2]]
 Output: false
 Explanation:
 No path exists from (0, 0) to (3, 3).
 Example 3:
 Input: xCorner = 3, yCorner = 3, circles = [[2,1,1],[1,2,1]]
 Output: false
 Explanation:
 No path exists from (0, 0) to (3, 3).
 Example 4:
 Input: xCorner = 4, yCorner = 4, circles = [[5,5,1]]
 Output: true
 Explanation:
 Constraints:
 3 <= xCorner, yCorner <= 109
 1 <= circles.length <= 1000
 circles[i].length == 3
 1 <= xi, yi, ri <= 109
*/

class Solution {
    public boolean canReachCorner(int xCorner, int yCorner, int[][] circles) {
        
        int n = circles.length;
        boolean[][] visited = new boolean[n][n];
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, 0});
        while(!q.isEmpty()) {
            int[] curr = q.poll();
            int x = curr[0];
            int y = curr[1];
            
            if(x == xCorner && y == yCorner) {
                return true;
            }
            
            for(int i = 0; i < n; i++) {
                int xi = circles[i][0];
                int yi = circles[i][1];
                int ri = circles[i][2];
                
                if(visited[i][x]) continue;
                
                if(Math.pow(x - xi, 2) + Math.pow(y - yi, 2) <= Math.pow( ri, 2)) {
                    visited[i][x] = true;
                    visited[i][y] = true;
                    if(dfs(x, y, visited, circles, n)) return true;
                }
            }
        }
        return false;
    }
}
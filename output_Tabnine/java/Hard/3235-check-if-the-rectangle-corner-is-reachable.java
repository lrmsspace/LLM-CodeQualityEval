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
        boolean[][] visited = new boolean[xCorner + 1][yCorner + 1];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0});
        visited[0][0] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int x = current[0];
            int y = current[1];

            if (x == xCorner && y == yCorner) {
                return true;
            }

            // Check if the next points are valid and not visited
            if (isValid(x + 1, y, xCorner, yCorner, circles, visited)) {
                queue.offer(new int[]{x + 1, y});
                visited[x + 1][y] = true;
            }
            if (isValid(x, y + 1, xCorner, yCorner, circles, visited)) {
                queue.offer(new int[]{x, y + 1});
                visited[x][y + 1] = true;
            }
        }

        return false;
    }

    private boolean isValid(int x, int y, int xCorner, int yCorner, int[][] circles, boolean[][] visited) {
        // Check if the point is inside the rectangle
        if (x < 0 || x > xCorner || y < 0 || y > yCorner) {
            return false;
        }

        // Check if the point is inside any circle
        for (int[] circle : circles) {
            int cx = circle[0];
            int cy = circle[1];
            int r = circle[2];
            if (Math.pow(x - cx, 2) + Math.pow(y - cy, 2) <= Math.pow(r, 2)) {
                return false;
            }
        }

        // Check if the point is already visited
        return !visited[x][y];
    }
}
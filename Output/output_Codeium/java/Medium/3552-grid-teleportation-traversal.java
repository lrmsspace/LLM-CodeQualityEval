/*
 You are given a 2D character grid matrix of size m x n, represented as an array of strings, where matrix[i][j] represents the cell at the intersection of the ith row and jth column. Each cell is one of the following:
 '.' representing an empty cell.
 '#' representing an obstacle.
 An uppercase letter ('A'-'Z') representing a teleportation portal.
 You start at the top-left cell (0, 0), and your goal is to reach the bottom-right cell (m - 1, n - 1). You can move from the current cell to any adjacent cell (up, down, left, right) as long as the destination cell is within the grid bounds and is not an obstacle.
 If you step on a cell containing a portal letter and you haven't used that portal letter before, you may instantly teleport to any other cell in the grid with the same letter. This teleportation does not count as a move, but each portal letter can be used at most once during your journey.
 Return the minimum number of moves required to reach the bottom-right cell. If it is not possible to reach the destination, return -1.
 Example 1:
 Input: matrix = ["A..",".A.","..."]
 Output: 2
 Explanation:
 Before the first move, teleport from (0, 0) to (1, 1).
 In the first move, move from (1, 1) to (1, 2).
 In the second move, move from (1, 2) to (2, 2).
 Example 2:
 Input: matrix = [".#...",".#.#.",".#.#.","...#."]
 Output: 13
 Explanation:
 Constraints:
 1 <= m == matrix.length <= 103
 1 <= n == matrix[i].length <= 103
 matrix[i][j] is either '#', '.', or an uppercase English letter.
 matrix[0][0] is not an obstacle.
*/

class Solution {
    public int minMoves(String[] matrix) {
        int m = matrix.length;
        int n = matrix[0].length();
        int[][] directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        Queue<int[]> queue = new LinkedList<>();
        Map<Character, List<int[]>> portals = new HashMap<>();
        boolean[][] visited = new boolean[m][n];
        queue.offer(new int[]{0, 0});
        visited[0][0] = true;
        int moves = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = matrix[i].charAt(j);
                if (c >= 'A' && c <= 'Z') {
                    portals.computeIfAbsent(c, k -> new ArrayList<>()).add(new int[]{i, j});
                }
            }
        }

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] current = queue.poll();
                int x = current[0];
                int y = current[1];
                if (x == m - 1 && y == n - 1) {
                    return moves;
                }
                for (int[] dir : directions) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY] && matrix[newX].charAt(newY) != '#') {
                        visited[newX][newY] = true;
                        queue.offer(new int[]{newX, newY});
                    }
                }
                char c = matrix[x].charAt(y);
                if (portals.containsKey(c)) {
                    for (int[] pos : portals.get(c)) {
                        if (!visited[pos[0]][pos[1]]) {
                            visited[pos[0]][pos[1]] = true;
                            queue.offer(pos);
                        }
                    }
                    portals.remove(c);
                }
            }
            moves++;
        }
        return -1;

    }
}
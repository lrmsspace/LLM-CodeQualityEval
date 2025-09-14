/*
 You are given an m x n grid classroom where a student volunteer is tasked with cleaning up litter scattered around the room. Each cell in the grid is one of the following:
 'S': Starting position of the student
 'L': Litter that must be collected (once collected, the cell becomes empty)
 'R': Reset area that restores the student's energy to full capacity, regardless of their current energy level (can be used multiple times)
 'X': Obstacle the student cannot pass through
 '.': Empty space
 You are also given an integer energy, representing the student's maximum energy capacity. The student starts with this energy from the starting position 'S'.
 Each move to an adjacent cell (up, down, left, or right) costs 1 unit of energy. If the energy reaches 0, the student can only continue if they are on a reset area 'R', which resets the energy to its maximum capacity energy.
 Return the minimum number of moves required to collect all litter items, or -1 if it's impossible.
 Example 1:
 Input: classroom = ["S.", "XL"], energy = 2
 Output: 2
 Explanation:
 The student starts at cell (0, 0) with 2 units of energy.
 Since cell (1, 0) contains an obstacle 'X', the student cannot move directly downward.
 A valid sequence of moves to collect all litter is as follows:
 Move 1: From (0, 0) → (0, 1) with 1 unit of energy and 1 unit remaining.
 Move 2: From (0, 1) → (1, 1) to collect the litter 'L'.
 The student collects all the litter using 2 moves. Thus, the output is 2.
 Example 2:
 Input: classroom = ["LS", "RL"], energy = 4
 Output: 3
 Explanation:
 The student starts at cell (0, 1) with 4 units of energy.
 A valid sequence of moves to collect all litter is as follows:
 Move 1: From (0, 1) → (0, 0) to collect the first litter 'L' with 1 unit of energy used and 3 units remaining.
 Move 2: From (0, 0) → (1, 0) to 'R' to reset and restore energy back to 4.
 Move 3: From (1, 0) → (1, 1) to collect the second litter 'L'.
 The student collects all the litter using 3 moves. Thus, the output is 3.
 Example 3:
 Input: classroom = ["L.S", "RXL"], energy = 3
 Output: -1
 Explanation:
 No valid path collects all 'L'.
 Constraints:
 1 <= m == classroom.length <= 20
 1 <= n == classroom[i].length <= 20
 classroom[i][j] is one of 'S', 'L', 'R', 'X', or '.'
 1 <= energy <= 50
 There is exactly one 'S' in the grid.
 There are at most 10 'L' cells in the grid.
*/

class Solution {
    public int minMoves(String[] classroom, int energy) {
        int m = classroom.length;
        int n = classroom[0].length();
        int startX = -1, startY = -1;
        List<int[]> litterPositions = new ArrayList<>();
        boolean[][] visited = new boolean[m][n];
        
        // Find the starting position and litter positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char cell = classroom[i].charAt(j);
                if (cell == 'S') {
                    startX = i;
                    startY = j;
                } else if (cell == 'L') {
                    litterPositions.add(new int[]{i, j});
                }
            }
        }

        // If no litter is found, return 0 moves
        if (litterPositions.isEmpty()) {
            return 0;
        }

        // BFS to find the minimum moves to collect all litter
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{startX, startY, energy, 0}); // {x, y, remaining energy, moves}
        visited[startX][startY] = true;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int x = current[0], y = current[1], remainingEnergy = current[2], moves = current[3];

            // Check if all litter is collected
            if (litterPositions.isEmpty()) {
                return moves;
            }

            // Explore adjacent cells
            for (int[] dir : new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]) {
                    char cell = classroom[newX].charAt(newY);
                    if (cell != 'X') { // Not an obstacle
                        int newEnergy = remainingEnergy - 1;

                        // If it's a reset area, restore energy
                        if (cell == 'R') {
                            newEnergy = energy;
                        }

                        // If it's a litter cell, remove it from the list
                        if (cell == 'L') {
                            litterPositions.removeIf(pos -> pos[0] == newX && pos[1] == newY);
                        }
                        // If we have enough energy to move
                        if (newEnergy >= 0) {
                            visited[newX][newY] = true;
                            queue.offer(new int[]{newX, newY, newEnergy, moves + 1});
                        }
                    }
                }
            }
        }

        return -1; // If we cannot collect all litter
    }
}
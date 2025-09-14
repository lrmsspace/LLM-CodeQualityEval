/**https://leetcode.com/problems/sliding-puzzle/ */
//On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
//The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
//Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.
// 
//Example 1:
//Input: board = [[1,2,3],[4,0,5]]
//Output: 1
//Explanation: Swap the 0 and the 5 in one move.
//Example 2:
//Input: board = [[1,2,3],[5,4,0]]
//Output: -1
//Explanation: No number of moves will make the board solved.
//Example 3:
//Input: board = [[4,1,2],[5,0,3]]
//Output: 5
//Explanation: 5 is the smallest number of moves that solves the board.
//An example path:
//After move 0: [[4,1,2],[5,0,3]]
//After move 1: [[4,1,2],[0,5,3]]
//After move 2: [[0,1,2],[4,5,3]]
//After move 3: [[1,0,2],[4,5,3]]
//After move 4: [[1,2,0],[4,5,3]]
//After move 5: [[1,2,3],[4,5,0]]
// 
//Constraints:
//	board.length == 2
//	board[i].length == 3
//	0 <= board[i][j] <= 5
//	Each value board[i][j] is unique.
class Solution {
    public int slidingPuzzle(int[][] board) {
        String target = "123450";
        String start = board[0][0] + "" + board[0][1] + board[0][2] + board[1][0] + board[1][1] + board[1][2];
        if (start.equals(target)) return 0;
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.offer(start);
        visited.add(start);
        int moves = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String current = queue.poll();
                int zeroIndex = current.indexOf('0');
                int row = zeroIndex / 3;
                int col = zeroIndex % 3;
                for (int[] dir : directions) {
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    if (newRow >= 0 && newRow < 2 && newCol >= 0 && newCol < 3) {
                        StringBuilder nextState = new StringBuilder(current);
                        char temp = nextState.charAt(zeroIndex);
                        nextState.setCharAt(zeroIndex, nextState.charAt(newRow * 3 + newCol));
                        nextState.setCharAt(newRow * 3 + newCol, temp);
                        if (nextState.toString().equals(target)) return moves + 1;
                        if (!visited.contains(nextState.toString())) {
                            visited.add(nextState.toString());
                            queue.offer(nextState.toString());
                        }
                    }
                }
            }
            moves++;
        }
        return -1;        
    }
}
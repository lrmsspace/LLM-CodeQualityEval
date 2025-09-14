/**https://leetcode.com/problems/cat-and-mouse-ii/ */
//A game is played by a cat and a mouse named Cat and Mouse.
//The environment is represented by a grid of size rows x cols, where each element is a wall, floor, player (Cat, Mouse), or food.
//	Players are represented by the characters 'C'(Cat),'M'(Mouse).
//	Floors are represented by the character '.' and can be walked on.
//	Walls are represented by the character '#' and cannot be walked on.
//	Food is represented by the character 'F' and can be walked on.
//	There is only one of each character 'C', 'M', and 'F' in grid.
//Mouse and Cat play according to the following rules:
//	Mouse moves first, then they take turns to move.
//	During each turn, Cat and Mouse can jump in one of the four directions (left, right, up, down). They cannot jump over the wall nor outside of the grid.
//	catJump, mouseJump are the maximum lengths Cat and Mouse can jump at a time, respectively. Cat and Mouse can jump less than the maximum length.
//	Staying in the same position is allowed.
//	Mouse can jump over Cat.
//The game can end in 4 ways:
//	If Cat occupies the same position as Mouse, Cat wins.
//	If Cat reaches the food first, Cat wins.
//	If Mouse reaches the food first, Mouse wins.
//	If Mouse cannot get to the food within 1000 turns, Cat wins.
//Given a rows x cols matrix grid and two integers catJump and mouseJump, return true if Mouse can win the game if both Cat and Mouse play optimally, otherwise return false.
// 
//Example 1:
//Input: grid = ["####F","#C...","M...."], catJump = 1, mouseJump = 2
//Output: true
//Explanation: Cat cannot catch Mouse on its turn nor can it get the food before Mouse.
//Example 2:
//Input: grid = ["M.C...F"], catJump = 1, mouseJump = 4
//Output: true
//Example 3:
//Input: grid = ["M.C...F"], catJump = 1, mouseJump = 3
//Output: false
// 
//Constraints:
//	rows == grid.length
//	cols = grid[i].length
//	1 <= rows, cols <= 8
//	grid[i][j] consist only of characters 'C', 'M', 'F', '.', and '#'.
//	There is only one of each character 'C', 'M', and 'F' in grid.
//	1 <= catJump, mouseJump <= 8
class Solution {
    public boolean canMouseWin(String[] grid, int catJump, int mouseJump) {
        int rows = grid.length;
        int cols = grid[0].length();
        int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int[][][] dp = new int[rows][cols][2];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i].charAt(j) == 'C') {
                    dp[i][j][0] = 1;
                } else if (grid[i].charAt(j) == 'M') {
                    dp[i][j][0] = 2;
                } else if (grid[i].charAt(j) == 'F') {
                    dp[i][j][0] = 3;
                }
            }
        }
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[] {dp[0][0][0], 0, 0, 0});
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int catRow = cur[1], catCol = cur[2], mouseRow = cur[3], mouseCol = cur[4];
            if (dp[mouseRow][mouseCol][0] == 3) {
                return true;
            }
            if (dp[catRow][catCol][0] == 3 || dp[catRow][catCol][0] == 2) {
                continue;
            }
            for (int[] d : dir) {
                int newRow = catRow + d[0] * catJump, newCol = catCol + d[1] * catJump;
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow].charAt(newCol) != '#') {
                    int newMouseRow = mouseRow + d[0] * mouseJump, newMouseCol = mouseCol + d[1] * mouseJump;
                    if (newMouseRow >= 0 && newMouseRow < rows && newMouseCol >= 0 && newMouseCol < cols && grid[newMouseRow].charAt(newMouseCol) != '#') {
                        dp[newRow][newCol][0] = 1;
                        queue.offer(new int[] {1, newRow, newCol, newMouseRow, newMouseCol});
                    }
                }
            }
        }
        return false;
    }
}
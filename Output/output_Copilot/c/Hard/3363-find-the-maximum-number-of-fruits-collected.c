/*
 There is a game dungeon comprised of n x n rooms arranged in a grid.
 You are given a 2D array fruits of size n x n, where fruits[i][j] represents the number of fruits in the room (i, j). Three children will play in the game dungeon, with initial positions at the corner rooms (0, 0), (0, n - 1), and (n - 1, 0).
 The children will make exactly n - 1 moves according to the following rules to reach the room (n - 1, n - 1):
 The child starting from (0, 0) must move from their current room (i, j) to one of the rooms (i + 1, j + 1), (i + 1, j), and (i, j + 1) if the target room exists.
 The child starting from (0, n - 1) must move from their current room (i, j) to one of the rooms (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1) if the target room exists.
 The child starting from (n - 1, 0) must move from their current room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), and (i + 1, j + 1) if the target room exists.
 When a child enters a room, they will collect all the fruits there. If two or more children enter the same room, only one child will collect the fruits, and the room will be emptied after they leave.
 Return the maximum number of fruits the children can collect from the dungeon.
 Example 1:
 Input: fruits = [[1,2,3,4],[5,6,8,7],[9,10,11,12],[13,14,15,16]]
 Output: 100
 Explanation:
 In this example:
 The 1st child (green) moves on the path (0,0) -> (1,1) -> (2,2) -> (3, 3).
 The 2nd child (red) moves on the path (0,3) -> (1,2) -> (2,3) -> (3, 3).
 The 3rd child (blue) moves on the path (3,0) -> (3,1) -> (3,2) -> (3, 3).
 In total they collect 1 + 6 + 11 + 16 + 4 + 8 + 12 + 13 + 14 + 15 = 100 fruits.
 Example 2:
 Input: fruits = [[1,1],[1,1]]
 Output: 4
 Explanation:
 In this example:
 The 1st child moves on the path (0,0) -> (1,1).
 The 2nd child moves on the path (0,1) -> (1,1).
 The 3rd child moves on the path (1,0) -> (1,1).
 In total they collect 1 + 1 + 1 + 1 = 4 fruits.
 Constraints:
 2 <= n == fruits.length == fruits[i].length <= 1000
 0 <= fruits[i][j] <= 1000
*/

int maxCollectedFruits(int** fruits, int fruitsSize, int* fruitsColSize) {
    int n = fruitsSize;
    int dp[n][n][n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    
    dp[0][0][0] = fruits[0][0];
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k < n - 1; k++) {
                if (dp[i][j][k] == -1) continue;
                
                int x1 = i + 1, y1 = j + 1;
                int x2 = i + 1, y2 = j;
                int x3 = i, y3 = j + 1;
                
                if (x1 < n && y1 < n) {
                    dp[x1][y1][k] = fmax(dp[x1][y1][k], dp[i][j][k] + fruits[x1][y1]);
                }
                if (x2 < n && y2 >= 0) {
                    dp[x2][y2][k] = fmax(dp[x2][y2][k], dp[i][j][k] + fruits[x2][y2]);
                }
                if (x3 >= 0 && y3 < n) {
                    dp[x3][y3][k] = fmax(dp[x3][y3][k], dp[i][j][k] + fruits[x3][y3]);
                }
                
                x1 = i + 1, y1 = j - 1;
                x2 = i + 1, y2 = j;
                x3 = i + 1, y3 = j + 1;
                
                if (x1 < n && y1 >= 0) {
                    dp[x1][y1][k + 1] = fmax(dp[x1][y1][k + 1], dp[i][j][k] + fruits[x1][y1]);
                }
                if (x2 < n && y2 < n) {
                    dp[x2][y2][k + 1] = fmax(dp[x2][y2][k + 1], dp[i][j][k] + fruits[x2][y2]);
                }
                if (x3 < n && y3 < n) {
                    dp[x3][y3][k + 1] = fmax(dp[x3][y3][k + 1], dp[i][j][k] + fruits[x3][y3]);
                }

                x1 = i - 1, y1 = j + 1;
                x2 = i, y2 = j + 1;
                x3 = i + 1, y3 = j + 1;

                if (x1 >= 0 && y1 < n) {
                    dp[x1][y1][k] = fmax(dp[x1][y1][k], dp[i][j][k] + fruits[x1][y1]);
                }
                if (x2 >= 0 && y2 < n) {
                    dp[x2][y2][k] = fmax(dp[x2][y2][k], dp[i][j][k] + fruits[x2][y2]);
                }
                if (x3 < n && y3 < n) {
                    dp[x3][y3][k] = fmax(dp[x3][y3][k], dp[i][j][k] + fruits[x3][y3]);
                }
            }
        }
    }

    int maxFruits = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                maxFruits = fmax(maxFruits, dp[i][j][k]);
            }
        }
    }

    return maxFruits;
}
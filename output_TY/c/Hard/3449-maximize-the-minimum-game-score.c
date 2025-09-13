/*
 You are given an array points of size n and an integer m. There is another array gameScore of size n, where gameScore[i] represents the score achieved at the ith game. Initially, gameScore[i] == 0 for all i.
 You start at index -1, which is outside the array (before the first position at index 0). You can make at most m moves. In each move, you can either:
 Increase the index by 1 and add points[i] to gameScore[i].
 Decrease the index by 1 and add points[i] to gameScore[i].
 Note that the index must always remain within the bounds of the array after the first move.
 Return the maximum possible minimum value in gameScore after at most m moves.
 Example 1:
 Input: points = [2,4], m = 3
 Output: 4
 Explanation:
 Initially, index i = -1 and gameScore = [0, 0].
 Move
 Index
 gameScore
 Increase i
 0
 [2, 0]
 Increase i
 1
 [2, 4]
 Decrease i
 0
 [4, 4]
 The minimum value in gameScore is 4, and this is the maximum possible minimum among all configurations. Hence, 4 is the output.
 Example 2:
 Input: points = [1,2,3], m = 5
 Output: 2
 Explanation:
 Initially, index i = -1 and gameScore = [0, 0, 0].
 Move
 Index
 gameScore
 Increase i
 0
 [1, 0, 0]
 Increase i
 1
 [1, 2, 0]
 Decrease i
 0
 [2, 2, 0]
 Increase i
 1
 [2, 4, 0]
 Increase i
 2
 [2, 4, 3]
 The minimum value in gameScore is 2, and this is the maximum possible minimum among all configurations. Hence, 2 is the output.
 Constraints:
 2 <= n == points.length <= 5 * 104
 1 <= points[i] <= 106
 1 <= m <= 109
*/

long long maxScore(int* points, int pointsSize, int m) {
    int i, j, k, n = pointsSize;
    long long gameScore[n][m + 1];
    for (i = 0; i < n; i++) {
        gameScore[i][0] = 0;
    }
    for (i = 1; i <= m; i++) {
        gameScore[0][i] = gameScore[0][i - 1] + points[0];
    }
        for (i = 1; i < n; i++) {
            for (j = 1; j <= m; j++) {
                gameScore[i][j] = gameScore[i - 1][j];
                for (k = 1; k <= j && k <= i; k++) {
                    gameScore[i][j] = max(gameScore[i][j], gameScore[i - k][j - k] + points[i]);
                }
            }
        }
        return gameScore[n - 1][m];
    
}
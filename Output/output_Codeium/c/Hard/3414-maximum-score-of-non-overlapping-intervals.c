/*
 You are given a 2D integer array intervals, where intervals[i] = [li, ri, weighti]. Interval i starts at position li and ends at ri, and has a weight of weighti. You can choose up to 4 non-overlapping intervals. The score of the chosen intervals is defined as the total sum of their weights.
 Return the lexicographically smallest array of at most 4 indices from intervals with maximum score, representing your choice of non-overlapping intervals.
 Two intervals are said to be non-overlapping if they do not share any points. In particular, intervals sharing a left or right boundary are considered overlapping.
 Example 1:
 Input: intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]]
 Output: [2,3]
 Explanation:
 You can choose the intervals with indices 2, and 3 with respective weights of 5, and 3.
 Example 2:
 Input: intervals = [[5,8,1],[6,7,7],[4,7,3],[9,10,6],[7,8,2],[11,14,3],[3,5,5]]
 Output: [1,3,5,6]
 Explanation:
 You can choose the intervals with indices 1, 3, 5, and 6 with respective weights of 7, 6, 3, and 5.
 Constraints:
 1 <= intevals.length <= 5 * 104
 intervals[i].length == 3
 intervals[i] = [li, ri, weighti]
 1 <= li <= ri <= 109
 1 <= weighti <= 109
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maximumWeight(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize) {
    int dp[intervalsSize+1][5] = {0};
    int idx[5] = {0};
    for (int i = 0; i < intervalsSize; i++) {
        dp[i+1][0] = max(dp[i][0], dp[i][1], dp[i][2], dp[i][3], dp[i][4]);
        for (int j = 1; j <= 4; j++) {
            if (intervals[i][1] < intervals[idx[j-1]][0]) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-1] + intervals[i][2]);
                if (dp[i+1][j] > dp[i+1][j-1]) idx[j] = i;
            }
        }
    }
    int maxscore = 0;
    for (int i = 0; i < 5; i++) if (dp[intervalsSize][i] > maxscore) maxscore = dp[intervalsSize][i];
    int* res = (int*)malloc((maxscore != 0 ? 4 : 0)*sizeof(int));
    *returnSize = maxscore != 0 ? 4 : 0;
    for (int i = 3; i >= 0; i--) {
        if (maxscore == 0) break;
        res[i] = idx[i];
        maxscore -= intervals[idx[i]][2];
    }
    return res;
}
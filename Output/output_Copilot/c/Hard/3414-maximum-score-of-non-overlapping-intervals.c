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
    int* result = (int*)malloc(4 * sizeof(int));
    *returnSize = 0;
    
    // Sort intervals by their right endpoint
    qsort(intervals, intervalsSize, sizeof(int*), [](const void* a, const void* b) {
        int* intervalA = *(int**)a;
        int* intervalB = *(int**)b;
        return intervalA[1] - intervalB[1];
    });

    // Dynamic programming to find the maximum weight and corresponding indices
    int dp[5][intervalsSize];
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i < intervalsSize; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 0) {
                dp[j][i] = intervals[i][2]; // Base case: only one interval
            } else {
                dp[j][i] = dp[j][i - 1]; // Not taking the current interval
                for (int k = 0; k < i; k++) {
                    if (intervals[k][1] < intervals[i][0]) { // Non-overlapping condition
                        dp[j][i] = fmax(dp[j][i], dp[j - 1][k] + intervals[i][2]);
                    }
                }
            }
        }
    }

    // Find the maximum weight and corresponding indices
    int maxWeight = 0;
    for (int j = 0; j < 5; j++) {
        if (dp[j][intervalsSize - 1] > maxWeight) {
            maxWeight = dp[j][intervalsSize - 1];
            *returnSize = j + 1;
        }
    }

    // Backtrack to find the indices of the selected intervals
    int index = intervalsSize - 1;
    for (int j = *returnSize - 1; j >= 0; j--) {
        while (index >= 0 && dp[j][index] != maxWeight) {
            index--;
        }
        result[j] = index;
        maxWeight -= intervals[index][2];
        index--;
    }

    return result;
        
}
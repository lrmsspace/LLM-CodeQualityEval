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
    // Create array to store result indices
    int* result = (int*)malloc(4 * sizeof(int));
    *returnSize = 0;
    
    // Handle empty input
    if(intervalsSize == 0) {
        return result;
    }
    
    // dp[i][j] represents max weight for first i intervals using j intervals
    long long dp[50001][5] = {0};
    // prev[i][j] stores previous interval index for backtracking
    int prev[50001][5];
    memset(prev, -1, sizeof(prev));
    
    // For each interval i
    for(int i = 0; i < intervalsSize; i++) {
        // Copy previous state
        for(int j = 0; j <= 4; j++) {
            dp[i+1][j] = dp[i][j];
            prev[i+1][j] = prev[i][j];
        }
        
        // Try to add current interval
        for(int j = 1; j <= 4; j++) {
            // Find last non-overlapping interval
            int last = i-1;
            while(last >= 0) {
                if(intervals[last][1] < intervals[i][0]) {
                    break;
                }
                last--;
            }
            
            // Calculate new weight including current interval
            long long weight = (last >= 0 ? dp[last+1][j-1] : 0) + intervals[i][2];
            
            // Update if better weight found
            if(weight > dp[i+1][j]) {
                dp[i+1][j] = weight;
                prev[i+1][j] = i;
            }
        }
    }
    
    // Backtrack to find intervals
    int curr = intervalsSize;
    int count = 4;
    
    while(count > 0 && prev[curr][count] != -1) {
        result[*returnSize] = prev[curr][count];
        curr = prev[curr][count];
        (*returnSize)++;
        count--;
    }
    
    // Reverse result array
    for(int i = 0; i < *returnSize/2; i++) {
        int temp = result[i];
        result[i] = result[*returnSize-1-i];
        result[*returnSize-1-i] = temp;
    }
    
    return result;
}    
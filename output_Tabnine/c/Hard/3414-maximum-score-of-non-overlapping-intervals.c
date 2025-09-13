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

    // Sort the intervals based on their end points in ascending order
    qsort(intervals, intervalsSize, sizeof(intervals[0]), compareEndPoints);
    
    // Initialize the score and the chosen intervals
    int score = 0;
    int* chosenIntervals = malloc(sizeof(int) * 4);
    int chosenIntervalsSize = 0;
    
    // Iterate through the intervals
    for (int i = 0; i < intervalsSize; i++) {
        // If the chosen intervals size is less than 4 and the current interval is non-overlapping with the chosen intervals
        if (chosenIntervalsSize < 4 && isNonOverlapping(intervals[i], chosenIntervals, chosenIntervalsSize)) {
            // Add the current interval to the chosen intervals and update the score
            chosenIntervals[chosenIntervalsSize++] = i;
            score += intervals[i][2];
        }
    }
    
    // Sort the chosen intervals based on their indices in ascending order
    qsort(chosenIntervals, chosenIntervalsSize, sizeof(int), compareIndices);
    
    // Set the return size and return the chosen intervals
    *returnSize = chosenIntervalsSize;
    return chosenIntervals;
    
}
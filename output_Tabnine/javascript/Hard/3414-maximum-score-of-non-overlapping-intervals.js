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
 * @param {number[][]} intervals
 * @return {number[]}
 */
var maximumWeight = function(intervals) {
    // Sort the intervals based on their start times
    intervals.sort((a, b) => a[0] - b[0]);
    
    // Initialize variables to keep track of the maximum score and the indices of the chosen intervals
    let maxScore = 0;
    let chosenIndices = [];
    let currentScore = 0;
    let currentIndices = [];
    let left = 0;
    let right = 0;
    let i = 0;
    let j = 0;

    // Iterate through the intervals
    while (i < intervals.length && j < intervals.length) {
        // If the current interval starts before the previous interval ends, choose it
        if (intervals[i][0] <= intervals[j][1]) {
            if (intervals[i][2] + currentScore > maxScore) {
                maxScore = intervals[i][2] + currentScore;
                chosenIndices = [...currentIndices, i];
            }
            currentScore += intervals[i][2];
            currentIndices.push(i);
            left = Math.min(left, intervals[i][0]);
            right = Math.max(right, intervals[i][1]);
            i++;
        } else {
            // If the current interval ends before the next interval starts, choose the next interval
            currentScore -= intervals[j][2];
            currentIndices = currentIndices.filter((_, index) => index!== j);
            j++;
            left = intervals[j][0];
            right = intervals[j][1];
            i = j;
            currentScore = intervals[i][2];
            currentIndices.push(i);

            // Check if the chosen indices form a valid solution
            if (chosenIndices.length === 4 && right - left + 1 === 4) {
                return chosenIndices.sort((a, b) => a - b);
            }
        }
        // If the chosen indices form a valid solution, return it
        if (chosenIndices.length === 4 && right - left + 1 === 4) {
            return chosenIndices.sort((a, b) => a - b);
        }
    }
    // Return an empty array if no valid solution is found
    return [];
    
};
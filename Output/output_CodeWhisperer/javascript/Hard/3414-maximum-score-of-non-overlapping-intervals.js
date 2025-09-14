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
    intervals.sort((a, b) => {
        if (a[0] !== b[0]) {
            return a[0] - b[0];
        }
        if (a[1] !== b[1]) {
            return a[1] - b[1];
        }
        return a[2] - b[2];
    });
    const n = intervals.length;
    const dp = new Array(n).fill(0);
    let max = 0;
    let maxIndex = -1;
    for (let i = 0; i < n; i++) {
        dp[i] = intervals[i][2];
        for (let j = 0; j < i; j++) {
            if (intervals[j][1] <= intervals[i][0]) {
                dp[i] = Math.max(dp[i], dp[j] + intervals[i][2]);
            }
        }
        if (dp[i] > max) {
            max = dp[i];
            maxIndex = i;
        }
    }
    const result = [];
    let i = maxIndex;
    while (i >= 0) {
        if (i === 0 || dp[i] > dp[i - 1]) {
            result.push(i);
            max -= intervals[i][2];
            if (max === 0) {
                break;
            }
        }
        i--;
    }
    return result.map((i) => i).sort((a, b) => intervals[a][0] - intervals[b][0]).map((i) => i + 1);    
};
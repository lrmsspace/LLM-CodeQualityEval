/**https://leetcode.com/problems/non-overlapping-intervals/ */
//Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
//Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.
// 
//Example 1:
//Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
//Output: 1
//Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
//Example 2:
//Input: intervals = [[1,2],[1,2],[1,2]]
//Output: 2
//Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
//Example 3:
//Input: intervals = [[1,2],[2,3]]
//Output: 0
//Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
// 
//Constraints:
//	1 <= intervals.length <= 105
//	intervals[i].length == 2
//	-5 * 104 <= starti < endi <= 5 * 104
/**
 * @param {number[][]} intervals
 * @return {number}
 */
var eraseOverlapIntervals = function(intervals) {
    // Sort the intervals by end value
    intervals.sort((a, b) => a[1] - b[1]);
    // Initialize the count of non-overlapping intervals
    let count = 1;
    // Initialize the end value of the non-overlapping intervals
    let end = intervals[0][1];
    // Iterate through the intervals
    for (let i = 1; i < intervals.length; i++) {
        // If the current interval does not overlap with the previous one, increment the count and update the end value
        if (intervals[i][0] >= end) {
            count++;
            end = intervals[i][1];
        }
    }
    // Return the minimum number of intervals you need to remove
    return intervals.length - count;
};
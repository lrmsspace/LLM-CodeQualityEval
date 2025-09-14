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
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        // Sort intervals by end time
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);
        
        int end = intervals[0][1]; // End time of the first interval
        int count = 1; // Count of non-overlapping intervals
        
        for (int i = 1; i < intervals.length; i++) {
            // If the start time of the current interval is greater than the end time of the previous interval,
            // it means the current interval doesn't overlap with the previous one, so we can add it to the count
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
                count++;
            }
        }
        
        return intervals.length - count; // Return the number of intervals to be removed
        
    }
}
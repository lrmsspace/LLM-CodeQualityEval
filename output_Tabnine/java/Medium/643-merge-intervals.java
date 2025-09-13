/**https://leetcode.com/problems/merge-intervals/ */
//Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
// 
//Example 1:
//Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
//Output: [[1,6],[8,10],[15,18]]
//Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
//Example 2:
//Input: intervals = [[1,4],[4,5]]
//Output: [[1,5]]
//Explanation: Intervals [1,4] and [4,5] are considered overlapping.
// 
//Constraints:
//	1 <= intervals.length <= 104
//	intervals[i].length == 2
//	0 <= starti <= endi <= 104
class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length == 0) {
            return new int[0][];
        }
        
        // Sort the intervals based on their start times
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        
        List<int[]> mergedIntervals = new ArrayList<>();
        mergedIntervals.add(intervals[0]);
        
        for (int[] interval : intervals) {
            int[] lastMergedInterval = mergedIntervals.get(mergedIntervals.size() - 1);
            
            if (interval[0] <= lastMergedInterval[1]) {
                // Merge the current interval with the last merged interval
                lastMergedInterval[1] = Math.max(lastMergedInterval[1], interval[1]);
            } else {
                // Start a new merged interval
                mergedIntervals.add(interval);
            }
        }
        
        return mergedIntervals.toArray(new int[mergedIntervals.size()][]);
        
    }
}
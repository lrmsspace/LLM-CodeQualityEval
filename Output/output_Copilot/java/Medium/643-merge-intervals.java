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
        // Sort the intervals based on the start time
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        
        List<int[]> merged = new ArrayList<>();
        
        for (int[] interval : intervals) {
            // If the list of merged intervals is empty or if the current interval does not overlap with the previous one, add it to the merged list
            if (merged.isEmpty() || merged.get(merged.size() - 1)[1] < interval[0]) {
                merged.add(interval);
            } else {
                // Otherwise, there is an overlap, so we merge the current interval with the previous one
                merged.get(merged.size() - 1)[1] = Math.max(merged.get(merged.size() - 1)[1], interval[1]);
            }
        }
        
        return merged.toArray(new int[merged.size()][]);        
    }
}
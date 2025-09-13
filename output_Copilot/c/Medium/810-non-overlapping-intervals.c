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
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) {
        return 0;
    }
    // sort by end
    for (int i = 0; i < intervalsSize; i++) {
        for (int j = i + 1; j < intervalsSize; j++) {
            if (intervals[i][1] > intervals[j][1]) {
                int tmp = intervals[i][0];
                intervals[i][0] = intervals[j][0];
                intervals[j][0] = tmp;
                tmp = intervals[i][1];
                intervals[i][1] = intervals[j][1];
                intervals[j][1] = tmp;
            }
        }
    }
    int count = 1;
    int end = intervals[0][1];
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] >= end) {
            count++;
            end = intervals[i][1];
        }
    }
    return intervalsSize - count;    
}
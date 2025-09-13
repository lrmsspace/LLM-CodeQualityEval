/**https://leetcode.com/problems/insert-interval/ */
//You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
//Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
//Return intervals after the insertion.
//Note that you don't need to modify intervals in-place. You can make a new array and return it.
// 
//Example 1:
//Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
//Output: [[1,5],[6,9]]
//Example 2:
//Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
//Output: [[1,2],[3,10],[12,16]]
//Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
// 
//Constraints:
//	0 <= intervals.length <= 104
//	intervals[i].length == 2
//	0 <= starti <= endi <= 105
//	intervals is sorted by starti in ascending order.
//	newInterval.length == 2
//	0 <= start <= end <= 105
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * (intervalsSize + 1));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (intervalsSize + 1));
    int i = 0, j = 0;
    while (i < intervalsSize && intervals[i][1] < newInterval[0]) {
        result[j] = intervals[i];
        (*returnColumnSizes)[j] = intervalsColSize[i];
        j++;
        i++;
    }
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = fmin(newInterval[0], intervals[i][0]);
        newInterval[1] = fmax(newInterval[1], intervals[i][1]);
        i++;
    }
    result[j] = newInterval;
    (*returnColumnSizes)[j] = 2;
    j++;
    while (i < intervalsSize) {
        result[j] = intervals[i];
        (*returnColumnSizes)[j] = intervalsColSize[i];
        j++;
        i++;
    }
    *returnSize = j;
    return result;
}
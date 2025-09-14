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
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (intervalsSize == 0) {
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(int[2]), compare);
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    int j = 0;
    result[j] = (int*)malloc(2 * sizeof(int));
    result[j][0] = intervals[0][0];
    result[j][1] = intervals[0][1];
    *returnSize = 1;
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] > result[j][1]) {
            j++;
            result[j] = (int*)malloc(2 * sizeof(int));
            result[j][0] = intervals[i][0];
            result[j][1] = intervals[i][1];
            (*returnSize)++;
        } else {
            result[j][1] = (result[j][1] > intervals[i][1]) ? result[j][1] : intervals[i][1];
        }
    }
    (*returnColumnSizes) = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return result;
}

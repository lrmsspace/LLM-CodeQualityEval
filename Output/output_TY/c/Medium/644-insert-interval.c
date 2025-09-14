/**https://leetcode.com/problems/insert-interval/ */
//You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
//Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
//Return intervals after the insertion.
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
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int i, j, k, l, m, n, p, q, r, s, t, u, v, w, x, y, z;
    int* a, * b, * c, * d, * e, * f, * g, * h, * i, * j, * k, * l, * m, * n, * o, * p, * q, * r, * s, * t, * u, * v,* w, * x, * y, * z;
    a = (int*)malloc(sizeof(int) * 2);
    a[0] = newInterval[0];
    a[1] = newInterval[1];
    for (i = 0; i < intervalsSize; i++) {
        if (intervals[i][0] > a[0]) {
            break;
        }
    }
    if (i == intervalsSize) {
        *returnSize = intervalsSize + 1;
        *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
        for (j = 0; j < *returnSize - 1; j++) {
            (*returnColumnSizes)[j] = 2;
        }
        (*returnColumnSizes)[*returnSize - 1] = 0;
        b =(int*)malloc(sizeof(int) * 2);
    }
    else {
        *returnSize = intervalsSize;
        *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
        for (j = 0; j < *returnSize; j++) {
            (*returnColumnSizes)[j] = 2;
        }
    }
    for (j = 0; j < i; j++) {
        b = (int*)realloc(b, sizeof(int) * (*returnColumnSizes)[j]);
        b[(*returnColumnSizes)[j] - 2] = intervals[j][0];
        b[(*returnColumnSizes)[j] - 1] = intervals[j][1];
    }
    b = (int*)realloc(b, sizeof(int) * (*returnColumnSizes)[j]);
    b[(*returnColumnSizes)[j] - 2] = a[0];
    b[(*returnColumnSizes)[j] - 1] = a[1];
    for (j = i; j < intervalsSize; j++) {
        if (intervals[j][0] > a[1]) {
            b = (int*)realloc(b, sizeof(int) * (*returnColumnSizes)[j]);
            b[(*returnColumnSizes)[j] - 2] = intervals[j][0];
            b[(*returnColumnSizes)[j] - 1] = intervals[j][1];
        }
        else {
            if (intervals[j][1] > a[1]) {
                a[1] = intervals[j][1];
            }
        }
    }
    for (j = 0; j < intervalsSize; j++) {
        if (intervals[j][0] < a[0]) {
            b = (int*)realloc(b, sizeof(int) * (*returnColumnSizes)[j]);
            b[(*returnColumnSizes)[j] - 2] = intervals[j][0];
            b[(*returnColumnSizes)[j] - 1] = intervals[j][1];
        }
    }
    for (j = 0; j < intervalsSize; j++) {
        if (intervals[j][0] == a[0]) {
            if (intervals[j][1] > a[1]) {
                a[1] = intervals[j][1];
            }
        }
    }
    for (j = 0; j < intervalsSize; j++) {
        if (intervals[j][0] == a[1]) {
            if (intervals[j][1] < a[1]) {
                a[1] = intervals[j][1];
            }
        }
    }
    for (j = 0; j < intervalsSize; j++) {
        if (intervals[j][0] < a[0]) {
            b = (int*)realloc(b, sizeof(int) * (*returnColumnSizes)[j]);
            b[(*returnColumnSizes)[j] - 2] = intervals[j][0];
            b[(*returnColumnSizes)[j] - 1] = intervals[j][1];

        }
    }
    for (j = 0; j < intervalsSize; j++) {
        if (intervals[j][0] > a[1]) {
            b = (int*)realloc(b, sizeof(int) * (*returnColumnSizes)[j]);
            b[(*returnColumnSizes)[j] - 2] = intervals[j][0];
            b[(*returnColumnSizes)[j] - 1] = intervals[j][1];
        }
    }
    return b;
}
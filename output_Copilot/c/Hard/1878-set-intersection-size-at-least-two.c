/**https://leetcode.com/problems/set-intersection-size-at-least-two/ */
//You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.
//A containing set is an array nums where each interval from intervals has at least two integers in nums.
//	For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
//Return the minimum possible size of a containing set.
// 
//Example 1:
//Input: intervals = [[1,3],[3,7],[8,9]]
//Output: 5
//Explanation: let nums = [2, 3, 4, 8, 9].
//It can be shown that there cannot be any containing array of size 4.
//Example 2:
//Input: intervals = [[1,3],[1,4],[2,5],[3,5]]
//Output: 3
//Explanation: let nums = [2, 3, 4].
//It can be shown that there cannot be any containing array of size 2.
//Example 3:
//Input: intervals = [[1,2],[2,3],[2,4],[4,5]]
//Output: 5
//Explanation: let nums = [1, 2, 3, 4, 5].
//It can be shown that there cannot be any containing array of size 4.
// 
//Constraints:
//	1 <= intervals.length <= 3000
//	intervals[i].length == 2
//	0 <= starti < endi <= 108
int intersectionSizeTwo(int** intervals, int intervalsSize, int* intervalsColSize) {
       qsort(intervals, intervalsSize, sizeof(int*), compare);
        int result = 0;
        int n = intervalsSize;
        int* dp = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            dp[i] = 2;
        }
        for (int i = n - 1; i >= 0; i--) {
            int count = dp[i];
            int start = intervals[i][0];
            int end = intervals[i][1];
            for (int j = start; j < start + count; j++) {
                for (int k = i - 1; k >= 0; k--) {
                    if (intervals[k][0] <= j && j <= intervals[k][1]) {
                        dp[k] = fmax(dp[k], count + 1);
                    }
                }
            }
            result = fmax(result, count);
        }
        free(dp);
        return result;     
}
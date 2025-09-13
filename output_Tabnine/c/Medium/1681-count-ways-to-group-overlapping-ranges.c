/**https://leetcode.com/problems/count-ways-to-group-overlapping-ranges/ */
//You are given a 2D integer array ranges where ranges[i] = [starti, endi] denotes that all integers between starti and endi (both inclusive) are contained in the ith range.
//You are to split ranges into two (possibly empty) groups such that:
//	Each range belongs to exactly one group.
//	Any two overlapping ranges must belong to the same group.
//Two ranges are said to be overlapping if there exists at least one integer that is present in both ranges.
//	For example, [1, 3] and [2, 5] are overlapping because 2 and 3 occur in both ranges.
//Return the total number of ways to split ranges into two groups. Since the answer may be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: ranges = [[6,10],[5,15]]
//Output: 2
//Explanation: 
//The two ranges are overlapping, so they must be in the same group.
//Thus, there are two possible ways:
//- Put both the ranges together in group 1.
//- Put both the ranges together in group 2.
//Example 2:
//Input: ranges = [[1,3],[10,20],[2,5],[4,8]]
//Output: 4
//Explanation: 
//Ranges [1,3], and [2,5] are overlapping. So, they must be in the same group.
//Again, ranges [2,5] and [4,8] are also overlapping. So, they must also be in the same group. 
//Thus, there are four possible ways to group them:
//- All the ranges in group 1.
//- All the ranges in group 2.
//- Ranges [1,3], [2,5], and [4,8] in group 1 and [10,20] in group 2.
//- Ranges [1,3], [2,5], and [4,8] in group 2 and [10,20] in group 1.
// 
//Constraints:
//	1 <= ranges.length <= 105
//	ranges[i].length == 2
//	0 <= starti <= endi <= 109
int countWays(int** ranges, int rangesSize, int* rangesColSize) {
    // Sort the ranges based on their starting points
    qsort(ranges, rangesSize, sizeof(int*), compare);
    
    int group1 = 0, group2 = 0;
    for (int i = 0; i < rangesSize; i++) {
        int start = ranges[i][0], end = ranges[i][1];
        
        // If the current range overlaps with the last range in group 1, merge them
        if (group1 > 0 && ranges[group1 - 1][1] >= start) {
            ranges[group1 - 1][1] = max(ranges[group1 - 1][1], end);
        } else {
            // Otherwise, create a new group with the current range
            group1++;
            ranges[group1 - 1][0] = start;
            ranges[group1 - 1][1] = end;
        }
    }
    
    // Calculate the number of ways to group the ranges in group 1 and group 2
    long long ways = 1;
    for (int i = 0; i < group1; i++) {
        ways = (ways * (ranges[i][1] - ranges[i][0] + 1)) % MOD;
    }
    for (int i = group1; i < rangesSize; i++) {
        ways = (ways * (ranges[i][1] - ranges[i][0] + 1)) % MOD;
    }
    
    return (int)ways;
    
}
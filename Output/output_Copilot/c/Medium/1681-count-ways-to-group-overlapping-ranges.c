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

#define MOD 1000000007

        // Comparator function for sorting ranges by start, and by end if starts are equal
        int compare(const void* a, const void* b) {
            int* rangeA = *(int**)a;
            int* rangeB = *(int**)b;
            if (rangeA[0] != rangeB[0]) {
                return rangeA[0] - rangeB[0];
            }
            return rangeA[1] - rangeB[1];
        }

        int countWays(int** ranges, int rangesSize, int* rangesColSize) {
            // Sort ranges by start, and by end if starts are equal
            qsort(ranges, rangesSize, sizeof(int*), compare);

            int groups = 1; // At least one group is needed
            int currentEnd = ranges[0][1];

            // Merge overlapping ranges and count groups
            for (int i = 1; i < rangesSize; i++) {
                if (ranges[i][0] > currentEnd) {
                    groups++;
                }
                currentEnd = (ranges[i][1] > currentEnd) ? ranges[i][1] : currentEnd;
            }

            // Calculate 2^groups % MOD
            long long result = 1;
            for (int i = 0; i < groups; i++) {
                result = (result * 2) % MOD;
            }

            return (int)result;
        }
    
            

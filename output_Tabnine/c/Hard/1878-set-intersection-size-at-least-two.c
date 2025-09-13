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
    // Sort the intervals based on the start value
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    
    // Initialize the minimum size of the containing set
    int minSize = INT_MAX;
    
    // Initialize pointers for the two intervals
    int left = 0, right = 1;
    
    // Iterate through the sorted intervals
    while (right < intervalsSize) {
        // If the current interval overlaps with the next interval, merge them
        if (intervals[left][1] >= intervals[right][0]) {
            intervals[left][1] = max(intervals[left][1], intervals[right][1]);
            right++;
        } else {
            // If the current interval does not overlap with the next interval, increment the left pointer
            left++;
            right++;
        }
        
        // Update the minimum size of the containing set
        minSize = min(minSize, intervals[left][1] - intervals[left][0] + 1);
    }
    
    // Return the minimum possible size of a containing set
    return minSize;
    
}
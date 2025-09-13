/**https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/ */
//You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
//We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
// 
//Example 1:
//Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
//Output: [20,24]
//Explanation: 
//List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
//List 2: [0, 9, 12, 20], 20 is in range [20,24].
//List 3: [5, 18, 22, 30], 22 is in range [20,24].
//Example 2:
//Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
//Output: [1,1]
// 
//Constraints:
//	nums.length == k
//	1 <= k <= 3500
//	1 <= nums[i].length <= 50
//	-105 <= nums[i][j] <= 105
//	nums[i] is sorted in non-decreasing order.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int k = numsSize;
    int* pointers = (int*)malloc(sizeof(int) * k);
    int min = INT_MAX;
    int max = INT_MIN;
    int minIndex = -1;
    int maxIndex = -1;
    int minRange = INT_MAX;
    int minRangeStart = -1;
    int minRangeEnd = -1;
    for (int i = 0; i < k; i++) {
        pointers[i] = 0;
    }
    while (1) {
        for (int i = 0; i < k; i++) {
            if (pointers[i] == numsColSize[i]) {
                result[0] = minRangeStart;
                result[1] = minRangeEnd;
                return result;
            }
            if (nums[i][pointers[i]] < min) {
                min = nums[i][pointers[i]];
                minIndex = i;
            }
            if (nums[i][pointers[i]] > max) {
                max = nums[i][pointers[i]];
                maxIndex = i;
            }
        }
        if (max - min < minRange) {
            minRange = max - min;
            minRangeStart = min;
            minRangeEnd = max;
        }
        pointers[minIndex]++;
        min = INT_MAX;
        max = INT_MIN;
    }
    result[0] = minRangeStart;
    result[1] = minRangeEnd;
    return result;
}
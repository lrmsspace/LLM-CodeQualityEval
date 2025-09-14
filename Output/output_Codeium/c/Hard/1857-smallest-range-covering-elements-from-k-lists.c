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
    int min_val = INT_MAX, max_val = INT_MIN;
    for (int i = 0; i < numsSize; ++i) {
        min_val = fmin(min_val, nums[i][0]);
        max_val = fmax(max_val, nums[i][numsColSize[i] - 1]);
    }
    int min_range = max_val - min_val;
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = min_val;
    res[1] = max_val;
    *returnSize = 2;
    return res;
    
}
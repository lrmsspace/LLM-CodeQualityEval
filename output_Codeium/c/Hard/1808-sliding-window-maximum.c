/**https://leetcode.com/problems/sliding-window-maximum/ */
//You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//Return the max sliding window.
// 
//Example 1:
//Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
//Output: [3,3,5,5,6,7]
//Explanation: 
//Window position                Max
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
//Example 2:
//Input: nums = [1], k = 1
//Output: [1]
// 
//Constraints:
//	1 <= nums.length <= 105
//	-104 <= nums[i] <= 104
//	1 <= k <= nums.length
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int *res = (int *)malloc((numsSize - k + 1) * sizeof(int));
    int i = 0, j = 0, max = INT_MIN;
    for (i = 0; i < numsSize; i++) {
        if (i >= k) {
            if (nums[j] == max) {
                max = INT_MIN;
                for (int l = j + 1; l < i; l++) {
                    if (nums[l] > max)
                        max = nums[l];
                }
            }
            j++;
        }
        if (nums[i] > max)
            max = nums[i];
        if (i >= k - 1)
            res[i - k + 1] = max;
    }
    *returnSize = numsSize - k + 1;
    return res;
}

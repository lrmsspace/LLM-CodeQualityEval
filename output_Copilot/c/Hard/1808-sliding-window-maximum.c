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
    int *res = (int *)malloc(sizeof(int) * (numsSize - k + 1));
    int *max = (int *)malloc(sizeof(int) * numsSize);
    int maxIndex = -1;
    int left = 0, right = 0;
    for (int i = 0; i < numsSize; i++) {
        if (maxIndex >= left && maxIndex < right && i - k >= left) {
            left++;
            maxIndex = left;
            for (int j = left + 1; j < right; j++) {
                if (nums[j] > nums[maxIndex]) {
                    maxIndex = j;
                }
            }
        }
        if (maxIndex < left || nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
        if (right - left + 1 == k) {
            res[left] = nums[maxIndex];
            left++;
            maxIndex = left;
            for (int j = left + 1; j < right; j++) {
                if (nums[j] > nums[maxIndex]) {
                    maxIndex = j;
                }
            }
        }
        right++;
    }
    *returnSize = numsSize - k + 1;
    return res;    
}
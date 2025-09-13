/**https://leetcode.com/problems/sliding-window-median/ */
//The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.
//	For examples, if arr = [2,3,4], the median is 3.
//	For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
//You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.
// 
//Example 1:
//Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
//Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
//Explanation: 
//Window position                Median
//---------------                -----
//[1  3  -1] -3  5  3  6  7        1
// 1 [3  -1  -3] 5  3  6  7       -1
// 1  3 [-1  -3  5] 3  6  7       -1
// 1  3  -1 [-3  5  3] 6  7        3
// 1  3  -1  -3 [5  3  6] 7        5
// 1  3  -1  -3  5 [3  6  7]       6
//Example 2:
//Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
//Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]
// 
//Constraints:
//	1 <= k <= nums.length <= 105
//	-231 <= nums[i] <= 231 - 1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    double *res = (double*)malloc(numsSize - k + 1 * sizeof(double));
    int idx = 0;
    for (int i = 0; i < numsSize - k + 1; ++i) {
        int left = i, right = i + k - 1;
        int count[k];
        memset(count, 0, k * sizeof(int));
        for (int j = left; j <= right; ++j) {
            count[nums[j]]++;
        }
        int mid = (k + 1) / 2;
        int sum = 0;
        for (int j = 0; j < k; ++j) {
            sum += count[j];
            if (sum >= mid) {
                if (k % 2 == 1) {
                    res[idx++] = (double)j;
                } else {
                    res[idx++] = (double)(j + (sum > mid ? 1 : 0)) / 2.0;
                }
                break;
            }
        }
    }
    *returnSize = idx;
    return res;
}

/**https://leetcode.com/problems/find-the-k-sum-of-an-array/ */
//You are given an integer array nums and a positive integer k. You can choose any subsequence of the array and sum all of its elements together.
//We define the K-Sum of the array as the kth largest subsequence sum that can be obtained (not necessarily distinct).
//Return the K-Sum of the array.
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
//Note that the empty subsequence is considered to have a sum of 0.
// 
//Example 1:
//Input: nums = [2,4,-2], k = 5
//Output: 2
//Explanation: All the possible subsequence sums that we can obtain are the following sorted in decreasing order:
//- 6, 4, 4, 2, 2, 0, 0, -2.
//The 5-Sum of the array is 2.
//Example 2:
//Input: nums = [1,-2,3,4,-10,12], k = 16
//Output: 10
//Explanation: The 16-Sum of the array is 10.
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 105
//	-109 <= nums[i] <= 109
//	1 <= k <= min(2000, 2n)
long long kSum(int* nums, int numsSize, int k) {
    int* sums = (int*)malloc(sizeof(int) * (numsSize + 1));
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        sums[i + 1] = sum;
    }
    sums[0] = 0;
    int* heap = (int*)malloc(sizeof(int) * (numsSize + 1));
    int heapSize = 0;
    heap[heapSize++] = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < heapSize; j++) {
            int index = heap[j];
            int x = sums[i + 1] - sums[index + 1];
            heap[j] = i + 1;
            int l = 0, r = heapSize;
            while (l < r) {
                int mid = (l + r) / 2;
                if (x < heap[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (l == heapSize) {
                heap[heapSize++] = i + 1;
            } else {
                for (int k = heapSize - 1; k > l; k--) {
                    heap[k] = heap[k - 1];
                }
                heap[l] = i + 1;
            }
        }
    }
    long long result = 0;
    for (int i = 0; i < heapSize; i++) {
        result += sums[heap[i]];
    }
    free(sums);
    free(heap);
    return result;
}
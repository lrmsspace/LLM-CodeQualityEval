/*
 You are given an integer array nums and two integers k and numOperations.
 You must perform an operation numOperations times on nums, where in each operation you:
 Select an index i that was not selected in any previous operations.
 Add an integer in the range [-k, k] to nums[i].
 Return the maximum possible frequency of any element in nums after performing the operations.
 Example 1:
 Input: nums = [1,4,5], k = 1, numOperations = 2
 Output: 2
 Explanation:
 We can achieve a maximum frequency of two by:
 Adding 0 to nums[1], after which nums becomes [1, 4, 5].
 Adding -1 to nums[2], after which nums becomes [1, 4, 4].
 Example 2:
 Input: nums = [5,11,20,20], k = 5, numOperations = 1
 Output: 2
 Explanation:
 We can achieve a maximum frequency of two by:
 Adding 0 to nums[1].
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 109
 0 <= k <= 109
 0 <= numOperations <= nums.length
*/

int maxFrequency(int* nums, int numsSize, int k, int numOperations) {
    int* freq = (int*)calloc(100001, sizeof(int));
    int* freqSum = (int*)calloc(100001, sizeof(int));
    int maxFreq = 0;
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }
    for (int i = 1; i <= 100000; i++) {
        freqSum[i] = freqSum[i - 1] + freq[i];
    }
    for (int i = 1; i <= 100000; i++) {
        int l = 0, r = i - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int sum = (i - mid) * (freqSum[i] - freqSum[mid]);
            if (sum <= k) {
                maxFreq = fmax(maxFreq, freqSum[i] - freqSum[mid] + numOperations);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    free(freq);
    free(freqSum);
    return maxFreq;    
}
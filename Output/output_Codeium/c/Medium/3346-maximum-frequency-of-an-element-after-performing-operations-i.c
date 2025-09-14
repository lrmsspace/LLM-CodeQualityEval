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
 Adding 0 to nums[1]. nums becomes [1, 4, 5].
 Adding -1 to nums[2]. nums becomes [1, 4, 4].
 Example 2:
 Input: nums = [5,11,20,20], k = 5, numOperations = 1
 Output: 2
 Explanation:
 We can achieve a maximum frequency of two by:
 Adding 0 to nums[1].
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 105
 0 <= k <= 105
 0 <= numOperations <= nums.length
*/

int maxFrequency(int* nums, int numsSize, int k, int numOperations) {
    int maxFreq = 0, freq = 1;
    int prev = nums[0], curr;
    for (int i = 1; i < numsSize; i++) {
        curr = nums[i];
        if (curr == prev) {
            freq++;
        } else {
            maxFreq = max(maxFreq, freq);
            freq = 1;
            prev = curr;
        }
    }
    maxFreq = max(maxFreq, freq);
    
    int left = 0, right = numsSize - 1;
    int diff;
    while (left < right && numOperations > 0) {
        diff = nums[right] - nums[left];
        if (diff <= k * 2) {
            int move = min(diff / 2, k);
            nums[right] -= move;
            nums[left] += move;
            numOperations -= move;
            left++;
            right--;
        } else {
            break;
        }
    }
    
    return maxFreq + numOperations;
}
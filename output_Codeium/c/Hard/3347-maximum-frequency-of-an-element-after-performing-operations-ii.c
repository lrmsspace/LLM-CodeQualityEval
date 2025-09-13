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
    int maxFreq = 0, freq = 0, target = 0, need = k + 1;
    int l = 0, r = 0;
    int count[100001] = {0};
    
    while (r < numsSize) {
        if (count[nums[r]]++ == 0) need--;
        while (need > 0) {
            if (--count[nums[l++]] == 0) need++;
        }
        target = nums[r];
        freq = r - l + 1;
        while (r + 1 < numsSize && nums[r + 1] <= target + k) {
            if (count[nums[++r]]++ == 0) need--;
            while (need > 0) {
                if (--count[nums[l++]] == 0) need++;
            }
            freq = r - l + 1;
        }
        maxFreq = max(maxFreq, freq);
    }
    
    return maxFreq;
}
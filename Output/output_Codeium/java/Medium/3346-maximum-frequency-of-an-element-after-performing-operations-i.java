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

class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        int n = nums.length;
        int[] count = new int[n + 2 * k + 1];
        for (int num : nums) {
            count[num + k]++;
        }
        int maxFreq = 0;
        int left = 0;
        int right = 0;
        int total = 0;
        while (right < count.length) {
            total += count[right];
            while (total > numOperations) {
                total -= count[left];
                left++;
            }
            maxFreq = Math.max(maxFreq, total);
            right++;
        }
        return maxFreq;
    }
}
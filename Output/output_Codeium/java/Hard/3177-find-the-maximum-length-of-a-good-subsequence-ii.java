/*
 You are given an integer array nums and a non-negative integer k. A sequence of integers seq is called good if there are at most k indices i in the range [0, seq.length - 2] such that seq[i] != seq[i + 1].
 Return the maximum possible length of a good subsequence of nums.
 Example 1:
 Input: nums = [1,2,1,1,3], k = 2
 Output: 4
 Explanation:
 The maximum length subsequence is [1,2,1,1,3].
 Example 2:
 Input: nums = [1,2,3,4,5,1], k = 0
 Output: 2
 Explanation:
 The maximum length subsequence is [1,2,3,4,5,1].
 Constraints:
 1 <= nums.length <= 5 * 103
 1 <= nums[i] <= 109
 0 <= k <= min(50, nums.length)
*/

class Solution {
    public int maximumLength(int[] nums, int k) {
        int maxLength = 0;
        int currentLength = 0;
        int differences = 0;

        for (int i = 0; i < nums.length; i++) {
            currentLength = 1;
            differences = 0;

            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] != nums[j - 1]) {
                    differences++;
                }
                if (differences > k) {
                    break;
                }
                currentLength++;
            }
            maxLength = Math.max(maxLength, currentLength);
        }

        return maxLength;

    }
}
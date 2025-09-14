/*
 You are given an integer array nums and a positive integer k.
 Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
 A subarray is a contiguous sequence of elements within an array.
 Example 1:
 Input: nums = [1,3,2,3,3], k = 2
 Output: 6
 Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
 Example 2:
 Input: nums = [1,4,2,1], k = 3
 Output: 0
 Explanation: No subarray contains the element 4 at least 3 times.
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 106
 1 <= k <= 105
*/

class Solution {
    public long countSubarrays(int[] nums, int k) {
        long count = 0;
        int maxElement = nums[0];
        int maxCount = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > maxElement) {
                maxElement = nums[i];
                maxCount = 1;
            } else if (nums[i] == maxElement) {
                maxCount++;
            }

            if (i >= k - 1) {
                if (maxCount >= k) {
                    count += (long) (i - k + 2);
                }

                if (nums[i - k + 1] == maxElement) {
                    maxCount--;
                }
            }
        }

        return count;
    }
}
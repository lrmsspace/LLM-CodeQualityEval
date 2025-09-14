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
        long ans = 0;
        int n = nums.length;
        int[] freq = new int[1000001]; // Assuming nums[i] <= 10^6
        int left = 0, right = 0, maxFreq = 0;

        while (right < n) {
            freq[nums[right]]++;
            maxFreq = Math.max(maxFreq, freq[nums[right]]);

            while (maxFreq >= k) {
                ans += n - right; // Count all subarrays starting from left to right
                freq[nums[left]]--;
                if (freq[nums[left]] < k) {
                    maxFreq = Math.max(maxFreq, freq[nums[left]]);
                }
                left++;
            }
            right++;
        }

        return ans;        
    }
}
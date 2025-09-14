/*
 Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.
 Example 1:
 Input: nums = [1,2,1,4,1]
 Output: 1
 Explanation:
 Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.
 Example 2:
 Input: nums = [1,1,1]
 Output: 0
 Explanation:
 [1,1,1] is the only subarray of length 3. However, its first and third numbers do not add to half the middle number.
 Constraints:
 3 <= nums.length <= 100
 -100 <= nums[i] <= 100
*/

class Solution {
    public int countSubarrays(int[] nums) {
        int n = nums.length;
        int count = 0;
        int sum = 0;
        
        // Count the number of subarrays ending at each index
        int[] prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            prefixSum[i + 1] = sum;
        }
        
        // Iterate through the prefix sum array and check for subarrays with sum equal to half the second number
        for (int i = 2; i <= n; i++) {
            int half = prefixSum[i] / 2;
            count += prefixSum[i] - prefixSum[i - 2] - half;
        }
        
        return count;
        
    }
}
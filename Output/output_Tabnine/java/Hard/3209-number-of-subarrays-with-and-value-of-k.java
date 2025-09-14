/*
 Given an array of integers nums and an integer k, return the number of subarrays of nums where the bitwise AND of the elements of the subarray equals k.
 Example 1:
 Input: nums = [1,1,1], k = 1
 Output: 6
 Explanation:
 All subarrays contain only 1's.
 Example 2:
 Input: nums = [1,1,2], k = 1
 Output: 3
 Explanation:
 Subarrays having an AND value of 1 are: [1,1,2], [1,1,2], [1,1,2].
 Example 3:
 Input: nums = [1,2,3], k = 2
 Output: 2
 Explanation:
 Subarrays having an AND value of 2 are: [1,2,3], [1,2,3].
 Constraints:
 1 <= nums.length <= 105
 0 <= nums[i], k <= 109
*/

class Solution {
    public long countSubarrays(int[] nums, int k) {
        // Initialize counters for subarrays with AND value of 1 and k
        int count1 = 0;
        int countK = 0;
        
        // Initialize prefix sum array
        int[] prefixSum = new int[nums.length + 1];
        prefixSum[0] = 1;
        
        // Iterate through the array and update prefix sums
        for (int i = 1; i <= nums.length; i++) {
            prefixSum[i] = prefixSum[i - 1] & nums[i - 1];
        }
        
        // Iterate through the prefix sums and count subarrays with AND value of 1
        for (int i = 0; i <= nums.length; i++) {
            if (prefixSum[i] == 1) {
                count1++;
            }
            
            // Count subarrays with AND value of k
            countK += count1;
        }
        
        return countK;  
        
    }
}
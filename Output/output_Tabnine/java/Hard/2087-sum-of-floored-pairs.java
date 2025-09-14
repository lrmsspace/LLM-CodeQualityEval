/**https://leetcode.com/problems/sum-of-floored-pairs/ */
//Given an integer array nums, return the sum of floor(nums[i] / nums[j]) for all pairs of indices 0 <= i, j < nums.length in the array. Since the answer may be too large, return it modulo 109 + 7.
//The floor() function returns the integer part of the division.
// 
//Example 1:
//Input: nums = [2,5,9]
//Output: 10
//Explanation:
//floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
//floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
//floor(5 / 2) = 2
//floor(9 / 2) = 4
//floor(9 / 5) = 1
//We calculate the floor of the division for every pair of indices in the array then sum them up.
//Example 2:
//Input: nums = [7,7,7,7,7,7,7]
//Output: 49
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 105
class Solution {
    public int sumOfFlooredPairs(int[] nums) {
        int MOD = 1000000007;
        int n = nums.length;
        int[] count = new int[101];
        int[] prefixSum = new int[n + 1];
        
        for (int num : nums) {
            count[num]++;
        }
        
        for (int i = 1; i <= 100; i++) {
            prefixSum[i] = prefixSum[i - 1] + count[i];
        }
        
        long ans = 0;
        
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            ans += (prefixSum[num] - prefixSum[Math.min(num, n - i - 1)]) * num;
            ans %= MOD;
        }
        
        return (int) ans;
        
    }
}
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
        int max = 0;
        for (int i = 0; i < nums.length; i++)
        {
            max = Math.max(max, nums[i]);
        }
        int[] freq = new int[max + 1];
        for (int i = 0; i < nums.length; i++)
        {
            freq[nums[i]]++;
        }
        int[] sum = new int[max + 1];
        for (int i = 1; i <= max; i++)
        {
            sum[i] = sum[i - 1] + freq[i];
        }
        long ans = 0;
        int mod = 1000000007;
        for (int i = 1; i <= max; i++)
        {
            if (freq[i] == 0) continue;
            for (int j = 1; j * i <= max; j++)
            {
                int left = j * i - 1;
                int right = Math.min(j * (i + 1) - 1, max);
                ans += (long)freq[i] * j * (sum[right] - sum[left]);
                ans %= mod;
            }
        }
        return (int)(ans % mod);      
    }
}
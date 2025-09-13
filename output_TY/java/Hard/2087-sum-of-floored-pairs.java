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
        int[] count = new int[100001];
        for (int num : nums) count[num]++;
        int[] prefix = new int[100001];
        for (int i = 1; i < 100001; i++) prefix[i] = prefix[i - 1] + count[i - 1];
        int ans = 0, mod = (int) 1e9 + 7;
        for (int i = 1; i < 100001; i++) {
            for (int j = i; j < 100001; j += i) {
                ans = (ans + (long) count[i] * (prefix[j] - prefix[i - 1]) *i) % mod;
            }
        }  
        return ans; 
    }
}
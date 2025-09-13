/*
 You are given an integer array nums.
 The factor score of an array is defined as the product of the LCM and GCD of all elements of that array.
 Return the maximum factor score of nums after removing at most one element from it.
 Note that both the LCM and GCD of a single number are the number itself, and the factor score of an empty array is 0.
 Example 1:
 Input: nums = [2,4,8,16]
 Output: 64
 Explanation:
 On removing 2, the GCD of the rest of the elements is 4 while the LCM is 16, which gives a maximum factor score of 4 * 16 = 64.
 Example 2:
 Input: nums = [1,2,3,4,5]
 Output: 60
 Explanation:
 The maximum factor score of 60 can be obtained without removing any elements.
 Example 3:
 Input: nums = [3]
 Output: 9
 Constraints:
 1 <= nums.length <= 100
 1 <= nums[i] <= 30
*/

class Solution {
    public long maxScore(int[] nums) {
        long ans = 0;
        int n = nums.length;
        long[] gcd = new long[n];
        long[] lcm = new long[n];
        for (int i = 0; i < n; i++) {
            gcd[i] = nums[i];
            lcm[i] = nums[i];
            for (int j = 0; j < i; j++) {
                long gcdj = gcd[j];
                long lcmj = lcm[j];
                gcd[i] = gcd(gcd[i], nums[j]);
                lcm[i] = lcm(lcm[i], nums[j]);
                gcd[j] = gcd(gcdj, nums[i]);
                lcm[j] = lcm(lcmj, nums[i]);
            }
            ans = Math.max(ans, (i == 0 ? 0 : lcm[i - 1]) * gcd[i]);
            ans = Math.max(ans, lcm[i] * (i + 1 == n ? 0 : gcd[i + 1]));
        }
        return ans;
            
    }
}
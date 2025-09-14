/**https://leetcode.com/problems/special-permutations/ */
//You are given a 0-indexed integer array nums containing n distinct positive integers. A permutation of nums is called special if:
//	For all indexes 0 <= i < n - 1, either nums[i] % nums[i+1] == 0 or nums[i+1] % nums[i] == 0.
//Return the total number of special permutations. As the answer could be large, return it modulo 109 + 7.
// 
//Example 1:
//Input: nums = [2,3,6]
//Output: 2
//Explanation: [3,6,2] and [2,6,3] are the two special permutations of nums.
//Example 2:
//Input: nums = [1,4,3]
//Output: 2
//Explanation: [3,1,4] and [4,1,3] are the two special permutations of nums.
// 
//Constraints:
//	2 <= nums.length <= 14
//	1 <= nums[i] <= 109
class Solution {
    public int specialPerm(int[] nums) {
        int MOD = 1_000_000_007;
        int n = nums.length;
        int[] dp = new int[1 << n];
        Arrays.fill(dp, -1);
        dp[0] = 1;
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 1) {
                    continue;
                }
                for (int k = 0; k < n; k++) {
                    if (j == k || ((i >> k) & 1) == 0) {
                        continue;
                    }
                    if (nums[j] % nums[k] == 0 || nums[k] % nums[j] == 0) {
                        dp[i | (1 << j)] = (dp[i | (1 << j)] + dp[i]) % MOD;
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
        
    }
}
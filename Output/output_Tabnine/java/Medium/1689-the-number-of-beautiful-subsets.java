/**https://leetcode.com/problems/the-number-of-beautiful-subsets/ */
//You are given an array nums of positive integers and a positive integer k.
//A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.
//Return the number of non-empty beautiful subsets of the array nums.
//A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.
// 
//Example 1:
//Input: nums = [2,4,6], k = 2
//Output: 4
//Explanation: The beautiful subsets of the array nums are: [2], [4], [6], [2, 6].
//It can be proved that there are only 4 beautiful subsets in the array [2,4,6].
//Example 2:
//Input: nums = [1], k = 1
//Output: 1
//Explanation: The beautiful subset of the array nums is [1].
//It can be proved that there is only 1 beautiful subset in the array [1].
// 
//Constraints:
//	1 <= nums.length <= 20
//	1 <= nums[i], k <= 1000
class Solution {
    public int beautifulSubsets(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int[][] dp = new int[n + 1][k + 1];
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    for (int l = 0; l < i; l++) {
                        if (Math.abs(nums[i] - nums[l]) == k) {
                            dp[i][j] = (dp[i][j] + dp[l][j - 1]) % (int) (1e9 + 7);
                        }
                    }
                }
                ans = (ans + dp[i][j]) % (int) (1e9 + 7);
            }
        }
        return ans;
        
    }
}
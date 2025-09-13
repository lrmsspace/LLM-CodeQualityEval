/**https://leetcode.com/problems/number-of-squareful-arrays/ */
//An array is squareful if the sum of every pair of adjacent elements is a perfect square.
//Given an integer array nums, return the number of permutations of nums that are squareful.
//Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].
// 
//Example 1:
//Input: nums = [1,17,8]
//Output: 2
//Explanation: [1,8,17] and [17,8,1] are the valid permutations.
//Example 2:
//Input: nums = [2,2,2]
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 12
//	0 <= nums[i] <= 109
class Solution {
    public int numSquarefulPerms(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int[] count = new int[1001];
        for (int num : nums) count[num]++;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++) {
                int diff = nums[j] - nums[i];
                if (diff < 0) diff += 1001;
                if (count[diff] > 0 && dp[i] * count[diff] > dp[j]) {
                    dp[j] = dp[i] * count[diff];
                    count[diff]--;
                }
            }
        int ans = 0;
        for (int num : dp) ans += num;
        return ans;
        
    }
}
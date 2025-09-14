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
        int[] dp = new int[1 << n];
        int[] cnt = new int[1001];
        for (int num : nums) {
            cnt[num]++;
        }
        dp[0] = 1;
        for (int mask = 1; mask < (1 << n); mask++) {
            int last = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    last = i;
                    break;
                }
            }
            dp[mask] = dp[mask ^ (1 << last)];
            for (int i = last + 1; i < n; i++) {
                if ((mask & (1 << i)) != 0 && Math.abs(nums[last] - nums[i]) >= k) {
                    dp[mask] += dp[mask ^ (1 << i)];
                }
            }
        }
        int ans = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            int[] freq = new int[1001];
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    freq[nums[i]]++;
                    sum++;
                }
            }
            long cur = 1;
            for (int i = 1; i <= 1000; i++) {
                for (int j = 1; j <= cnt[i]; j++) {
                    if (freq[i] >= j) {
                        cur *= sum--;
                        cur /= j;
                    }
                }
            }
            if (Integer.bitCount(mask) % 2 == 1) {
                ans += cur * dp[mask];
            } else {
                ans -= cur * dp[mask];
            }
        }   
        return ans; // Return the number of non-empty beautiful subsets of the array nums     
    }
}
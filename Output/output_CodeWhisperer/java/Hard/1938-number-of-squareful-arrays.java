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
import java.util.Arrays;
class Solution {
    public int numSquarefulPerms(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        int[] dp = new int[1 << n];
        Arrays.fill(dp, -1);
        dp[0] = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            int k = Integer.bitCount(mask);
            if (k == 1) {
                dp[mask] = 1;
                continue;
            }
            int[] arr = new int[k];
            int[] arr2 = new int[k];
            int j = 0;
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) != 0) {
                    arr[j] = nums[i];
                    arr2[j] = i;
                    ++j;
                }
            }
            int ans = 0;
            for (int i = 0; i < k; ++i) {
                if (i > 0 && arr[i] == arr[i - 1]) {
                    continue;
                }
                for (int j = i + 1; j < k; ++j) {
                    if (i == j) {
                        continue;
                    }
                    int x = arr[i] + arr[j];
                    int y = (int) Math.sqrt(x);
                    if (y * y == x) {
                        int mask2 = mask ^ (1 << arr2[i]) ^ (1 << arr2[j]);
                        ans += dp[mask2];
                    }
                }
                int x = arr[i] + arr[0];
                int y = (int) Math.sqrt(x);
                if (y * y == x) {
                    int mask2 = mask ^ (1 << arr2[i]) ^ (1 << arr2[0]);
                    ans += dp[mask2];
                }
            }
            dp[mask] = ans;
        }
        return dp[(1 << n) - 1];       
    }
}
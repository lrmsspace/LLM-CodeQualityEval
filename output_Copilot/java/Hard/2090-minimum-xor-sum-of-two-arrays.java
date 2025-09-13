/**https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/ */
//You are given two integer arrays nums1 and nums2 of length n.
//The XOR sum of the two integer arrays is (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) (0-indexed).
//	For example, the XOR sum of [1,2,3] and [3,2,1] is equal to (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4.
//Rearrange the elements of nums2 such that the resulting XOR sum is minimized.
//Return the XOR sum after the rearrangement.
// 
//Example 1:
//Input: nums1 = [1,2], nums2 = [2,3]
//Output: 2
//Explanation: Rearrange nums2 so that it becomes [3,2].
//The XOR sum is (1 XOR 3) + (2 XOR 2) = 2 + 0 = 2.
//Example 2:
//Input: nums1 = [1,0,3], nums2 = [5,3,4]
//Output: 8
//Explanation: Rearrange nums2 so that it becomes [5,4,3]. 
//The XOR sum is (1 XOR 5) + (0 XOR 4) + (3 XOR 3) = 4 + 4 + 0 = 8.
// 
//Constraints:
//	n == nums1.length
//	n == nums2.length
//	1 <= n <= 14
//	0 <= nums1[i], nums2[i] <= 107
class Solution {
    public int minimumXORSum(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[][] dp = new int[1 << n][n + 1];
        for (int i = 0; i < (1 << n); i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        dp[0][0] = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            int count = Integer.bitCount(mask);
            if (count > n) continue;
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << j)) == 0) {
                    int newMask = mask | (1 << j);
                    dp[newMask][count + 1] = Math.min(dp[newMask][count + 1], dp[mask][count] + (nums1[count] ^ nums2[j]));
                }
            }
        }
        return dp[(1 << n) - 1][n];        
    }
}
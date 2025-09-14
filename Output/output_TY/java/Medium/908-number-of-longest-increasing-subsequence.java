/**https://leetcode.com/problems/number-of-longest-increasing-subsequence/ */
//Given an integer array nums, return the number of longest increasing subsequences.
//Notice that the sequence has to be strictly increasing.
// 
//Example 1:
//Input: nums = [1,3,5,4,7]
//Output: 2
//Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
//Example 2:
//Input: nums = [2,2,2,2,2]
//Output: 5
//Explanation: The length of the longest increasing subsequence is 1, and there are 5 increasing subsequences of length 1, so output 5.
// 
//Constraints:
//	1 <= nums.length <= 2000
//	-106 <= nums[i] <= 106
//	The answer is guaranteed to fit inside a 32-bit integer.
class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        int[] dp_l = new int[n];
        int[] dp_c = new int[n];
        int max_l = 0;
        int max_c = 0;
        for (int i = 0; i < n; i++) {
            dp_l[i] = 1;
            dp_c[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) continue;
                if (dp_l[j] + 1 > dp_l[i]) {
                    dp_l[i] = dp_l[j] + 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (dp_l[i] > max_l) {
                max_l = dp_l[i];
                max_c = dp_c[i];
            } else if (dp_l[i] == max_l) {
                max_c += dp_c[i];
            }
        }
        return max_c;
    }
}
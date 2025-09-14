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
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumberOfLIS = function(nums) {
    const n = nums.length;
    const dp = new Array(n).fill(1);
    const count = new Array(n).fill(1);
    let maxLen = 1;
    
    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[j] + 1 === dp[i]) {
                    count[i] += count[j];
                }
            }
        }
        maxLen = Math.max(maxLen, dp[i]);
    }
    
    let ans = 0;
    for (let i = 0; i < n; i++) {
        if (dp[i] === maxLen) {
            ans += count[i];
        }
    }
    
    return ans;
    
};
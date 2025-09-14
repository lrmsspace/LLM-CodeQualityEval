/**https://leetcode.com/problems/longest-arithmetic-subsequence/ */
//Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.
//Note that:
//	A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
//	A sequence seq is arithmetic if seq[i + 1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).
// 
//Example 1:
//Input: nums = [3,6,9,12]
//Output: 4
//Explanation:  The whole array is an arithmetic sequence with steps of length = 3.
//Example 2:
//Input: nums = [9,4,7,2,10]
//Output: 3
//Explanation:  The longest arithmetic subsequence is [4,7,10].
//Example 3:
//Input: nums = [20,1,15,3,10,5,8]
//Output: 4
//Explanation:  The longest arithmetic subsequence is [20,15,10,5].
// 
//Constraints:
//	2 <= nums.length <= 1000
//	0 <= nums[i] <= 500
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestArithSeqLength = function(nums) {
    const n = nums.length;
    if (n < 3) return n;
    
    const dp = Array.from({length: n}, () => Array.from({length: n}, () => 2));
    let maxLen = 2;
    
    for (let i = 2; i < n; i++) {
        for (let j = 0; j < i; j++) {
            const diff = nums[i] - nums[j];
            for (let k = 0; k < j; k++) {
                if (Math.abs(nums[k] - nums[j]) === diff) {
                    dp[i][j] = Math.max(dp[i][j], dp[k][j] + 1);
                    maxLen = Math.max(maxLen, dp[i][j]);
                }
            }
        }
    }
    
    return maxLen;
    
};
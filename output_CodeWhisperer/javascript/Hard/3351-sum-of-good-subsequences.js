/*
 You are given an integer array nums. A good subsequence is defined as a subsequence of nums where the absolute difference between any two consecutive elements in the subsequence is exactly 1.
 Return the sum of all possible good subsequences of nums.
 Since the answer may be very large, return it modulo 109 + 7.
 Note that a subsequence of size 1 is considered good by definition.
 Example 1:
 Input: nums = [1,2,1]
 Output: 14
 Explanation:
 Good subsequences are: [1], [2], [1], [1,2], [2,1], [1,2,1].
 The sum of elements in these subsequences is 14.
 Example 2:
 Input: nums = [3,4,5]
 Output: 40
 Explanation:
 Good subsequences are: [3], [4], [5], [3,4], [4,5], [3,4,5].
 The sum of elements in these subsequences is 40.
 Constraints:
 1 <= nums.length <= 105
 0 <= nums[i] <= 105
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var sumOfGoodSubsequences = function(nums) {
    let freq = new Array(1001).fill(0);
    for (let num of nums) {
        freq[num]++;
    }
    
    let dp = new Array(1001).fill(0);
    dp[0] = 1;
    let mod = 1000000007;
    
    for (let i = 0; i < freq.length; i++) {
        let curr = new Array(1001).fill(0);
        for (let j = 0; j < 1001; j++) {
            curr[j] = dp[j];
            if (dp[j] > 0 && freq[i] > 0) {
                let k = j;
                while (k <= 1000) {
                    curr[k] = (curr[k] + dp[j] * freq[i]) % mod;
                    k++;
                }
            }
        }
        dp = curr;
    }
    
    let sum = 0;
    for (let i = 1; i < 1001; i++) {
        if (freq[i] > 0) {
            sum = (sum + dp[i]) % mod;
        }
    }
    
    return sum;
        
};
/*
 You are given an integer array nums.
 The factor score of an array is defined as the product of the LCM and GCD of all elements of that array.
 Return the maximum factor score of nums after removing at most one element from it.
 Note that both the LCM and GCD of a single number are the number itself, and the factor score of an empty array is 0.
 Example 1:
 Input: nums = [2,4,8,16]
 Output: 64
 Explanation:
 On removing 2, the GCD of the rest of the elements is 4 while the LCM is 16, which gives a maximum factor score of 4 * 16 = 64.
 Example 2:
 Input: nums = [1,2,3,4,5]
 Output: 60
 Explanation:
 The maximum factor score of 60 can be obtained without removing any elements.
 Example 3:
 Input: nums = [3]
 Output: 9
 Constraints:
 1 <= nums.length <= 100
 1 <= nums[i] <= 30
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxScore = function(nums) {
    let n = nums.length;
    let dp = new Array(1 << n).fill(0);
    for (let mask = 0; mask < (1 << n); mask++) {
        let count = 0;
        for (let i = 0; i < n; i++) {
            if ((mask & (1 << i)) > 0) {
                count++;
            }
        }
        if (count % 2 === 1) {
            continue;
        }
        for (let i = 0; i < n; i++) {
            if ((mask & (1 << i)) > 0) {
                for (let j = i + 1; j < n; j++) {
                    if ((mask & (1 << j)) > 0) {
                        dp[mask] = Math.max(dp[mask], dp[mask ^ (1 << i | 1 << j)]) + travelScore[i][j] + stayScore[0][j];
                    }
                }
            }
        }
    }
    return dp[(1 << n) - 1];
    
};
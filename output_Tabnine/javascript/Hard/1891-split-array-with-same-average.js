/**https://leetcode.com/problems/split-array-with-same-average/ */
//You are given an integer array nums.
//You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).
//Return true if it is possible to achieve that and false otherwise.
//Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.
// 
//Example 1:
//Input: nums = [1,2,3,4,5,6,7,8]
//Output: true
//Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have an average of 4.5.
//Example 2:
//Input: nums = [3,1]
//Output: false
// 
//Constraints:
//	1 <= nums.length <= 30
//	0 <= nums[i] <= 104
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var splitArraySameAverage = function(nums) {
    const n = nums.length;
    const total = nums.reduce((acc, val) => acc + val, 0);
    const target = total / n;
    
    const dp = Array(n + 1).fill(false).map(() => Array(target + 1).fill(false));
    dp[0][0] = true;
    
    for (let i = 1; i <= n; i++) {
        for (let j = 0; j <= target; j++) {
            if (dp[i - 1][j]) dp[i][j] = true;
            if (j >= nums[i - 1]) dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
        }
    }
    
    for (let i = target / 2; i <= target; i++) {
        if (dp[n][i]) return true;
    }
    
    return false;
    
};
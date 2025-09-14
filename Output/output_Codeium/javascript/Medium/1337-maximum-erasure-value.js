/**https://leetcode.com/problems/maximum-erasure-value/ */
//You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
//Return the maximum score you can get by erasing exactly one subarray.
//An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
// 
//Example 1:
//Input: nums = [4,2,4,5,6]
//Output: 17
//Explanation: The optimal subarray here is [2,4,5,6].
//Example 2:
//Input: nums = [5,2,1,2,5,2,1,2,5]
//Output: 8
//Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 104
/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumUniqueSubarray = function(nums) {
    let n = nums.length;
    let dp = new Array(n).fill(0);
    let curr = 0;
    let seen = new Set();
    let res = 0;
    
    for (let i = 0; i < n; i++) {
        if (seen.has(nums[i])) {
            curr = Math.max(curr - dp[i - 1], 0);
            seen.clear();
        }
        seen.add(nums[i]);
        curr += nums[i];
        dp[i] = curr;
        res = Math.max(res, curr);
    }
    
    return res;
};
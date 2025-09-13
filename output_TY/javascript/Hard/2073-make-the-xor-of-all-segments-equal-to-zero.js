/**https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/ */
//You are given an array nums​​​ and an integer k​​​​​. The XOR of a segment [left, right] where left <= right is the XOR of all the elements with indices between left and right, inclusive: nums[left] XOR nums[left+1] XOR ... XOR nums[right].
//Return the minimum number of elements to change in the array such that the XOR of all segments of size k​​​​​​ is equal to zero.
// 
//Example 1:
//Input: nums = [1,2,0,3,0], k = 1
//Output: 3
//Explanation: Modify the array from [1,2,0,3,0] to from [0,0,0,0,0].
//Example 2:
//Input: nums = [3,4,5,2,1,7,3,4,7], k = 3
//Output: 3
//Explanation: Modify the array from [3,4,5,2,1,7,3,4,7] to [3,4,7,3,4,7,3,4,7].
//Example 3:
//Input: nums = [1,2,4,1,2,5,1,2,6], k = 3
//Output: 3
//Explanation: Modify the array from [1,2,4,1,2,5,1,2,6] to [1,2,3,1,2,3,1,2,3].
// 
//Constraints:
//	1 <= k <= nums.length <= 2000
//	​​​​​​0 <= nums[i] < 210
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minChanges = function(nums, k) {
    const n = nums.length;
    const freq = new Array(n + 1).fill(0);
    for (const num of nums) freq[num]++;
    
    const freqCount = freq.filter(x => x !== 0);
    
    const dp = new Array(freqCount.length).fill(0).map(() => new Array(k + 1).fill(Infinity));
    
    for (let i = 0; i < freqCount.length; i++) {
        dp[i][1] = freqCount[i];
    }
    
    for (let i = 1; i <= k; i++) {
        for (let j = 0; j < freqCount.length;j++) {
            for (let l = 0; l < j; l++) {
                dp[j][i] = Math.min(dp[j][i], dp[l][i - 1] + (freqCount[j] - freqCount[l]) * i);
            }
        }
    } 
    return dp[freqCount.length - 1][k];
};
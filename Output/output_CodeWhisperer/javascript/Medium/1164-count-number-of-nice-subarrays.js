/**https://leetcode.com/problems/count-number-of-nice-subarrays/ */
//Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
//Return the number of nice sub-arrays.
// 
//Example 1:
//Input: nums = [1,1,2,1,1], k = 3
//Output: 2
//Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
//Example 2:
//Input: nums = [2,4,6], k = 1
//Output: 0
//Explanation: There are no odd numbers in the array.
//Example 3:
//Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
//Output: 16
// 
//Constraints:
//	1 <= nums.length <= 50000
//	1 <= nums[i] <= 10^5
//	1 <= k <= nums.length
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numberOfSubarrays = function(nums, k) {
    let n = nums.length;
    let count = new Array(n + 1).fill(0);
    count[0] = 1;
    let odd = 0, ans = 0;
    for (let i = 0; i < n; i++) {
        odd += nums[i] & 1;
        ans += odd >= k ? count[odd - k] : 0;
        count[odd] += 1;
    }
    return ans;
};
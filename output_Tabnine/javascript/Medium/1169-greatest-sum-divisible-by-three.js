/**https://leetcode.com/problems/greatest-sum-divisible-by-three/ */
//Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.
// 
//Example 1:
//Input: nums = [3,6,5,1,8]
//Output: 18
//Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
//Example 2:
//Input: nums = [4]
//Output: 0
//Explanation: Since 4 is not divisible by 3, do not pick any number.
//Example 3:
//Input: nums = [1,2,3,4,4]
//Output: 12
//Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
// 
//Constraints:
//	1 <= nums.length <= 4 * 104
//	1 <= nums[i] <= 104
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSumDivThree = function(nums) {
    // Sort the array in descending order
    nums.sort((a, b) => b - a);
    
    let sum1 = 0, sum2 = 0, sum3 = 0;
    
    // Iterate through the array and distribute the numbers into three groups
    for (let num of nums) {
        if (sum1 + num <= sum2) {
            sum1 += num;
        } else if (sum2 + num <= sum1) {
            sum2 += num;
        } else {
            sum3 += num;
        }
    }
    
    // Return the maximum sum that is divisible by 3
    return Math.max(sum1, sum2, sum3);
    
};
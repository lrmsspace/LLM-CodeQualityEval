/**https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/ */
//You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
//Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.
// 
//Example 1:
//Input: nums = [18,43,36,13,7]
//Output: 54
//Explanation: The pairs (i, j) that satisfy the conditions are:
//- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
//- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
//So the maximum sum that we can obtain is 54.
//Example 2:
//Input: nums = [10,12,19,14]
//Output: -1
//Explanation: There are no two numbers that satisfy the conditions, so we return -1.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 109
/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumSum = function(nums) {
    const map = new Map();
    let maxSum = -1;
    for (const num of nums) {
        const digitSum = String(num).split('').reduce((acc, digit) => acc + Number(digit), 0);
        if (map.has(digitSum)) {
            maxSum = Math.max(maxSum, map.get(digitSum) + num);
            map.set(digitSum, Math.max(map.get(digitSum), num));
        } else {
            map.set(digitSum, num);
        }
    }
    return maxSum;    
};
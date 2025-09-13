/**https://leetcode.com/problems/maximum-strength-of-a-group/ */
//You are given a 0-indexed integer array nums representing the score of students in an exam. The teacher would like to form one non-empty group of students with maximal strength, where the strength of a group of students of indices i0, i1, i2, ... , ik is defined as nums[i0] * nums[i1] * nums[i2] * ... * nums[ik​].
//Return the maximum strength of a group the teacher can create.
// 
//Example 1:
//Input: nums = [3,-1,-5,2,5,-9]
//Output: 1350
//Explanation: One way to form a group of maximal strength is to group the students at indices [0,2,3,4,5]. Their strength is 3 * (-5) * 2 * 5 * (-9) = 1350, which we can show is optimal.
//Example 2:
//Input: nums = [-4,-5,-4]
//Output: 20
//Explanation: Group the students at indices [0, 1] . Then, we’ll have a resulting strength of 20. We cannot achieve greater strength.
// 
//Constraints:
//	1 <= nums.length <= 13
//	-9 <= nums[i] <= 9
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxStrength = function(nums) {
    if (nums.length === 1) return nums[0];
    nums.sort((a, b) => a - b);
    let negativeCount = 0;
    let product = 1;
    let maxNegative = -Infinity;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] < 0) {
            negativeCount++;
            maxNegative = Math.max(maxNegative, nums[i]);
        }
        if (nums[i] !== 0) {
            product *= nums[i];
        }
    }
    if (negativeCount % 2 === 0) {
        return product;
    } else {
        return product / maxNegative;
    }
};
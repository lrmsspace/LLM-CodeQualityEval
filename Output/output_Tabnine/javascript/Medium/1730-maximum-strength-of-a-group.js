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
    // Sort the array in descending order
    nums.sort((a, b) => b - a);
    
    // Initialize the maximum strength to 0
    let maxStrength = 0;
    
    // Iterate through the array, multiplying the current element by the next element until we reach the end
    for (let i = 0; i < nums.length - 1; i++) {
        maxStrength *= nums[i] * nums[i + 1];
    }
    
    // Return the maximum strength
    return maxStrength;
    
};
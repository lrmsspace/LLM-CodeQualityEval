/*
 You are given an array of integers nums of size 3.
 Return the maximum possible number whose binary representation can be formed by concatenating the binary representation of all elements in nums in some order.
 Note that the binary representation of any number does not contain leading zeros.
 Example 1:
 Input: nums = [1,2,3]
 Output: 30
 Explanation:
 Concatenate the numbers in the order [3, 1, 2] to get the result "11110", which is the binary representation of 30.
 Example 2:
 Input: nums = [2,8,16]
 Output: 1296
 Explanation:
 Concatenate the numbers in the order [2, 8, 16] to get the result "10100010000", which is the binary representation of 1296.
 Constraints:
 nums.length == 3
 1 <= nums[i] <= 127
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxGoodNumber = function(nums) {
    // Sort the numbers in descending order
    nums.sort((a, b) => b - a);
    
    // Convert the numbers to binary strings
    const binaries = nums.map(num => num.toString(2));
    
    // Initialize the maximum possible number
    let maxNumber = 0;
    
    // Iterate through the binary strings and concatenate them to form the maximum possible number
    for (let i = 0; i < binaries.length; i++) {
        maxNumber = (maxNumber << 1) | parseInt(binaries[i]);
    }
    
    return maxNumber;   
    
};
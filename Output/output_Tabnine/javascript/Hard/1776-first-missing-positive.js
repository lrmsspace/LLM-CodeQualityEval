/**https://leetcode.com/problems/first-missing-positive/ */
//Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
//You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
// 
//Example 1:
//Input: nums = [1,2,0]
//Output: 3
//Explanation: The numbers in the range [1,2] are all in the array.
//Example 2:
//Input: nums = [3,4,-1,1]
//Output: 2
//Explanation: 1 is in the array but 2 is missing.
//Example 3:
//Input: nums = [7,8,9,11,12]
//Output: 1
//Explanation: The smallest positive integer 1 is missing.
// 
//Constraints:
//	1 <= nums.length <= 105
//	-231 <= nums[i] <= 231 - 1
/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    // First, sort the array
    nums.sort((a, b) => a - b);
    
    // Initialize a variable to track the missing number
    let missing = 1;
    
    // Iterate through the array
    for (let i = 0; i < nums.length; i++) {
        // If the current number is less than or equal to 0, skip it
        if (nums[i] <= 0) {
            continue;
        }
        
        // If the current number is equal to the missing number, increment the missing number
        if (nums[i] === missing) {
            missing++;
        }
        
        // If the current number is greater than the missing number, return it as the missing number
        else if (nums[i] > missing) {
            return missing;
        }
    }
    
    // If the loop completes without finding a missing number, return the missing number
    return missing;
    
};
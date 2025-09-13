/**https://leetcode.com/problems/3sum/ */
//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//Notice that the solution set must not contain duplicate triplets.
// 
//Example 1:
//Input: nums = [-1,0,1,2,-1,-4]
//Output: [[-1,-1,2],[-1,0,1]]
//Explanation: 
//nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
//nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
//nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
//The distinct triplets are [-1,0,1] and [-1,-1,2].
//Notice that the order of the output and the order of the triplets does not matter.
//Example 2:
//Input: nums = [0,1,1]
//Output: []
//Explanation: The only possible triplet does not sum up to 0.
//Example 3:
//Input: nums = [0,0,0]
//Output: [[0,0,0]]
//Explanation: The only possible triplet sums up to 0.
// 
//Constraints:
//	3 <= nums.length <= 3000
//	-105 <= nums[i] <= 105
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    // Sort the array
    nums.sort((a, b) => a - b);
    
    // Initialize an empty result array
    let result = [];
    
    // Iterate through the array
    for (let i = 0; i < nums.length - 2; i++) {
        // Skip duplicates
        if (i > 0 && nums[i] === nums[i - 1]) continue;
        
        // Initialize two pointers for the two remaining numbers
        let left = i + 1;
        let right = nums.length - 1;
        
        // Iterate through the remaining numbers

        while (left < right) {
            // Calculate the sum of the current triplet
            let sum = nums[i] + nums[left] + nums[right];
            
            // If the sum is 0, add the triplet to the result array
            if (sum === 0) {
                result.push([nums[i], nums[left], nums[right]]);
                
                // Skip duplicates
                while (left < right && nums[left] === nums[left + 1]) left++;
                while (left < right && nums[right] === nums[right - 1]) right--;
                
                // Move the pointers towards the center
                left++;
                right--;
            }
            // If the sum is less than 0, move the left pointer towards the center
            else if (sum < 0) left++;
            // If the sum is greater than 0, move the right pointer towards the center
            else right--;
        }
    }
    
    // Return the result array
    return result;
    
};
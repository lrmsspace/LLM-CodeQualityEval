/**https://leetcode.com/problems/find-all-duplicates-in-an-array/ */
//Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.
//You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output
// 
//Example 1:
//Input: nums = [4,3,2,7,8,2,3,1]
//Output: [2,3]
//Example 2:
//Input: nums = [1,1,2]
//Output: [1]
//Example 3:
//Input: nums = [1]
//Output: []
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 105
//	1 <= nums[i] <= n
//	Each element in nums appears once or twice.
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    // Initialize an empty object to store the frequency of each number
    let freq = {};
    
    // Iterate through the array
    for (let num of nums) {
        // If the number is already in the object, add it to the duplicates array
        if (freq[num]) {
            duplicates.push(num);
        } else {
            // Otherwise, add the number to the object with a frequency of 1
            freq[num] = 1;
        }
    }
    
    // Return the duplicates array
    return duplicates;
    
};
/**https://leetcode.com/problems/majority-element-ii/ */
//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// 
//Example 1:
//Input: nums = [3,2,3]
//Output: [3]
//Example 2:
//Input: nums = [1]
//Output: [1]
//Example 3:
//Input: nums = [1,2]
//Output: [1,2]
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	-109 <= nums[i] <= 109
// 
//Follow up: Could you solve the problem in linear time and in O(1) space?
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
    // Initialize counters for two candidates and their counts
    let candidate1 = null, candidate2 = null;
    let count1 = 0, count2 = 0;
    
    // Iterate through the array
    for (let num of nums) {
        // If candidate1 and candidate2 are the same, update their counts
        if (candidate1 === num) {
            count1++;
        } else if (candidate2 === num) {
            count2++;
        } else if (count1 === 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 === 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }
    
    // Check if the counts of candidates are valid
    let validCount1 = 0, validCount2 = 0;
    for (let num of nums) {
        if (num === candidate1) {
            validCount1++;
        } else if (num === candidate2) {
            validCount2++;
        }
    }
    
    // Return the majority elements
    const majorityElements = [];
    if (validCount1 > Math.floor(nums.length / 3)) {
        majorityElements.push(candidate1);
    }
    if (validCount2 > Math.floor(nums.length / 3)) {
        majorityElements.push(candidate2);
    }
    
    return majorityElements;
    
};
/**https://leetcode.com/problems/minimum-impossible-or/ */
//You are given a 0-indexed integer array nums.
//We say that an integer x is expressible from nums if there exist some integers 0 <= index1 < index2 < ... < indexk < nums.length for which nums[index1] | nums[index2] | ... | nums[indexk] = x. In other words, an integer is expressible if it can be written as the bitwise OR of some subsequence of nums.
//Return the minimum positive non-zero integer that is not expressible from nums.
// 
//Example 1:
//Input: nums = [2,1]
//Output: 4
//Explanation: 1 and 2 are already present in the array. We know that 3 is expressible, since nums[0] | nums[1] = 2 | 1 = 3. Since 4 is not expressible, we return 4.
//Example 2:
//Input: nums = [5,3,2]
//Output: 1
//Explanation: We can show that 1 is the smallest number that is not expressible.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 109
/**
 * @param {number[]} nums
 * @return {number}
 */
var minImpossibleOR = function(nums) {
    // Create a set to store the numbers we've seen so far
    let seen = new Set();
    
    // Iterate over the numbers in the array
    for (let num of nums) {
        // If the current number is already in the set, then it can be expressed as a bitwise OR of some subsequence of nums
        if (seen.has(num)) {
            // Keep adding 1 to the current number until we find a non-seen number
            let newNum = num + 1;
            while (seen.has(newNum)) {
                newNum++;
            }
            // Add the new number to the set
            seen.add(newNum);
            // Return the new number
            return newNum;
        }
        // Add the current number to the set
        seen.add(num);
    }
    
    // If we've gone through all the numbers and none can be expressed, return 1
    return 1;
    
};
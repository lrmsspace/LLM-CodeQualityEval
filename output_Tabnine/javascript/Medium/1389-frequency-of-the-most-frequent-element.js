/**https://leetcode.com/problems/frequency-of-the-most-frequent-element/ */
//The frequency of an element is the number of times it occurs in an array.
//You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.
//Return the maximum possible frequency of an element after performing at most k operations.
// 
//Example 1:
//Input: nums = [1,2,4], k = 5
//Output: 3
//Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
//4 has a frequency of 3.
//Example 2:
//Input: nums = [1,4,8,13], k = 5
//Output: 2
//Explanation: There are multiple optimal solutions:
//- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
//- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
//- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
//Example 3:
//Input: nums = [3,9,6], k = 2
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 105
//	1 <= k <= 105
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxFrequency = function(nums, k) {
    // Sort the array in ascending order
    nums.sort((a, b) => a - b);
    
    let maxFrequency = 1;
    let count = 1;
    
    // Iterate through the array from left to right
    for (let i = 1; i < nums.length; i++) {
        // If the current element is equal to the previous element, increment the count
        if (nums[i] === nums[i - 1]) {
            count++;
        } else {
            // If the count exceeds k, subtract the count from the total frequency
            if (count > k) {
                maxFrequency--;
            }
            count = 1;
        }
        
        // Update the maximum frequency if the current count is greater
        maxFrequency = Math.max(maxFrequency, count);
    }
    
    // If the count exceeds k, subtract the count from the total frequency
    if (count > k) {
        maxFrequency--;
    }
    
    return maxFrequency;
    
};
/*
 You are given an array nums consisting of positive integers.
 Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
 The frequency of an element is the number of occurrences of that element in the array.
 Example 1:
 Input: nums = [1,2,2,3,1,4]
 Output: 4
 Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
 So the number of elements in the array with maximum frequency is 4.
 Example 2:
 Input: nums = [1,2,3,4,5]
 Output: 5
 Explanation: All elements of the array have a frequency of 1 which is the maximum.
 So the number of elements in the array with maximum frequency is 5.
 Constraints:
 1 <= nums.length <= 100
 1 <= nums[i] <= 100
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var maxFrequencyElements = function(nums) {
    // Create a frequency map
    const freqMap = {};
    for (const num of nums) {
        freqMap[num] = (freqMap[num] || 0) + 1;
    }
    
    // Sort the frequency map by value in descending order
    const sortedFreqMap = Object.entries(freqMap).sort((a, b) => b[1] - a[1]);
    
    // Initialize the maximum frequency and count
    let maxFreq = sortedFreqMap[0][1];
    let count = 0;
    
    // Iterate through the sorted frequency map
    for (const [num, freq] of sortedFreqMap) {
        // If the current frequency is equal to the maximum frequency, increment the count
        if (freq === maxFreq) {
            count++;
        } else {
            // If the current frequency is different from the maximum frequency, break the loop
            break;
        }
    }   
    // Return the count of elements with the maximum frequency
    return count;   
    
};
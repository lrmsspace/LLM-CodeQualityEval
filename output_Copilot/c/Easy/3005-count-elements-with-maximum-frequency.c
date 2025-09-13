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

int maxFrequencyElements(int* nums, int numsSize) {
    int frequency[101] = {0}; // Array to count frequencies of elements (1 to 100)
    int maxFreq = 0; // Variable to track the maximum frequency
    int totalMaxFreqElements = 0; // Variable to track the total number of elements with maximum frequency

    // Count the frequency of each element
    for (int i = 0; i < numsSize; i++) {
        frequency[nums[i]]++;
        if (frequency[nums[i]] > maxFreq) {
            maxFreq = frequency[nums[i]]; // Update max frequency if current element's frequency is higher
        }
    }

    // Count how many elements have the maximum frequency
    for (int i = 1; i <= 100; i++) {
        if (frequency[i] == maxFreq) {
            totalMaxFreqElements += frequency[i]; // Add the count of this element to the total
        }
    }

    return totalMaxFreqElements; // Return the total count of elements with maximum frequency
    
}
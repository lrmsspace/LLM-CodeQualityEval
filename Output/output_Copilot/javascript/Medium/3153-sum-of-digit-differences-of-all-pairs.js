/*
 You are given an array nums consisting of positive integers where all integers have the same number of digits.
 The digit difference between two integers is the count of different digits that are in the same position in the two integers.
 Return the sum of the digit differences between all pairs of integers in nums.
 Example 1:
 Input: nums = [13,23,12]
 Output: 4
 Explanation:
 We have the following:
 - The digit difference between 13 and 23 is 1.
 - The digit difference between 13 and 12 is 1.
 - The digit difference between 23 and 12 is 2.
 So the total sum of digit differences between all pairs of integers is 1 + 1 + 2 = 4.
 Example 2:
 Input: nums = [10,10,10,10]
 Output: 0
 Explanation:
 All the integers in the array are the same. So the total sum of digit differences between all pairs of integers will be 0.
 Constraints:
 2 <= nums.length <= 105
 1 <= nums[i] < 109
 All integers in nums have the same number of digits.
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var sumDigitDifferences = function(nums) {
    const n = nums.length;
    const m = nums[0].toString().length; // Number of digits in each number
    let totalDifference = 0;

    // Iterate through each digit position
    for (let i = 0; i < m; i++) {
        const digitCount = new Array(10).fill(0); // Count of each digit from 0 to 9

        // Count the occurrences of each digit at position i
        for (let num of nums) {
            const digit = Math.floor(num / Math.pow(10, m - 1 - i)) % 10;
            digitCount[digit]++;
        }

        // Calculate the contribution of this digit position to the total difference
        for (let j = 0; j < 10; j++) {
            if (digitCount[j] > 0) {
                totalDifference += digitCount[j] * (n - digitCount[j]) * Math.abs(j);
            }
        }
    }

    return totalDifference;    
};
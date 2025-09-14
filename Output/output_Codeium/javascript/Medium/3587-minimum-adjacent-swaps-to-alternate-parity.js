/*
 You are given an array nums of distinct integers.
 In one operation, you can swap any two adjacent elements in the array.
 An arrangement of the array is considered valid if the parity of adjacent elements alternates, meaning every pair of neighboring elements consists of one even and one odd number.
 Return the minimum number of adjacent swaps required to transform nums into any valid arrangement.
 If it is impossible to rearrange nums such that no two adjacent elements have the same parity, return -1.
 Example 1:
 Input: nums = [2,4,6,5,7]
 Output: 3
 Explanation:
 Swapping 5 and 6, the array becomes [2,4,5,6,7]
 Swapping 5 and 4, the array becomes [2,5,4,6,7]
 Swapping 6 and 7, the array becomes [2,5,4,7,6]. The array is now a valid arrangement. Thus, the answer is 3.
 Example 2:
 Input: nums = [2,4,5,7]
 Output: 1
 Explanation:
 By swapping 4 and 5, the array becomes [2,5,4,7], which is a valid arrangement. Thus, the answer is 1.
 Example 3:
 Input: nums = [1,2,3]
 Output: 0
 Explanation:
 The array is already a valid arrangement. Thus, no operations are needed.
 Example 4:
 Input: nums = [4,5,6,8]
 Output: -1
 Explanation:
 No valid arrangement is possible. Thus, the answer is -1.
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 109
 All elements in nums are distinct.
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var minSwaps = function(nums) {
    let oddCount = 0;
    let evenCount = 0;
    let oddIndex = 0;
    let evenIndex = 0;

    // Count the odds and evens
    for (let num of nums) {
        if (num % 2 === 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    // Check if it's possible to alternate
    if (Math.abs(oddCount - evenCount) > 1) return -1;

    let swapsOddFirst = 0;
    let swapsEvenFirst = 0;

    // Calculate swaps needed for odd-first
    for (let i = 0; i < nums.length; i++) {
        if (i % 2 === 0 && nums[i] % 2 !== 0) {
            while (oddIndex < nums.length && nums[oddIndex] % 2 !== 0) oddIndex++;
            if (oddIndex < nums.length) {
                [nums[i], nums[oddIndex]] = [nums[oddIndex], nums[i]];
                swapsOddFirst++;
            }
        }
        if (i % 2 !== 0 && nums[i] % 2 !== 1) {
            while (evenIndex < nums.length && nums[evenIndex] % 2 !== 1) evenIndex++;
            if (evenIndex < nums.length) {
                [nums[i], nums[evenIndex]] = [nums[evenIndex], nums[i]];
                swapsOddFirst++;
            }
        }
    }

    // Reset indices for even-first calculation
    oddIndex = 0;
    evenIndex = 0;

    // Calculate swaps needed for even-first
    for (let i = 0; i < nums.length; i++) {
        if (i % 2 === 0 && nums[i] % 2 !== 1) {
            while (evenIndex < nums.length && nums[evenIndex] % 2 !== 1) evenIndex++;
            if (evenIndex < nums.length) {
                [nums[i], nums[evenIndex]] = [nums[evenIndex], nums[i]];
                swapsEvenFirst++;
            }
        }
        if (i % 2 !== 0 && nums[i] % 2 !== 0) {
            while (oddIndex < nums.length && nums[oddIndex] % 2 !== 0) oddIndex++;
            if (oddIndex < nums.length) {
                [nums[i], nums[oddIndex]] = [nums[oddIndex], nums[i]];
                swapsEvenFirst++;
            }
        }
    }

    return Math.min(swapsOddFirst, swapsEvenFirst);
};


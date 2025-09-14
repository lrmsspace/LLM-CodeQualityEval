/*
 You are given an integer array nums.
 Return an integer that is the maximum distance between the indices of two (not necessarily different) prime numbers in nums.
 Example 1:
 Input: nums = [4,2,9,5,3]
 Output: 3
 Explanation: nums[1], nums[3], and nums[4] are prime. So the answer is |4 - 1| = 3.
 Example 2:
 Input: nums = [4,8,2,8]
 Output: 0
 Explanation: nums[2] is prime. Because there is just one prime number, the answer is |2 - 2| = 0.
 Constraints:
 1 <= nums.length <= 3 * 105
 1 <= nums[i] <= 100
 The input is generated such that the number of prime numbers in the nums is at least one.
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumPrimeDifference = function(nums) {
    let max = 0;
    let min = 0;
    let maxPrime = 0;
    let minPrime = 0;
    let prime = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97];
    for(let i = 0; i < nums.length; i++) {
        if(prime.includes(nums[i])) {
            max = i;
            maxPrime = nums[i];
            break;
        }
    }
    for(let i = nums.length-1; i >= 0; i--) {
        if(prime.includes(nums[i])) {
            min = i;
            minPrime = nums[i];
            break;
        }
    }
    return Math.abs(max - min);
            
};
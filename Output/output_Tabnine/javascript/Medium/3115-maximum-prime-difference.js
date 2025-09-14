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
    let primes = [];
    for (let num of nums) {
        if (isPrime(num)) {
            primes.push(num);
        }
    }
    
    if (primes.length < 2) {
        return 0;
    }
    
    let maxDifference = 0;
    for (let i = 0; i < primes.length - 1; i++) {
        for (let j = i + 1; j < primes.length; j++) {
            maxDifference = Math.max(maxDifference, Math.abs(primes[i] - primes[j]));
        }
    }
    
    return maxDifference;   
    
};
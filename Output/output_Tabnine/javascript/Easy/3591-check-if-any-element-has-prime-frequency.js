/*
 You are given an integer array nums.
 Return true if the frequency of any element of the array is prime, otherwise, return false.
 The frequency of an element x is the number of times it occurs in the array.
 A prime number is a natural number greater than 1 with only two factors, 1 and itself.
 Example 1:
 Input: nums = [1,2,3,4,5,4]
 Output: true
 Explanation:
 4 has a frequency of two, which is a prime number.
 Example 2:
 Input: nums = [1,2,3,4,5]
 Output: false
 Explanation:
 All elements have a frequency of one.
 Example 3:
 Input: nums = [2,2,2,4,4]
 Output: true
 Explanation:
 Both 2 and 4 have a prime frequency.
 Constraints:
 1 <= nums.length <= 100
 0 <= nums[i] <= 100
*/

/**
 * @param {number[]} nums
 * @return {boolean}
 */
var checkPrimeFrequency = function(nums) {
    let frequencyMap = {};
    
    for (let num of nums) {
        frequencyMap[num] = (frequencyMap[num] || 0) + 1;
    }
    
    for (let frequency of Object.values(frequencyMap)) {
        if (!isPrime(frequency)) {
            return false;
        }
    }
    
    return true;
    
    function isPrime(num) {
        if (num <= 1) {
            return false;
        }
        
        for (let i = 2; i <= Math.sqrt(num); i++) {
            if (num % i === 0) {
                return false;
            }
        }
        
        return true;
    }
    
    
};
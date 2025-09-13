/**https://leetcode.com/problems/four-divisors/ */
//Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.
// 
//Example 1:
//Input: nums = [21,4,7]
//Output: 32
//Explanation: 
//21 has 4 divisors: 1, 3, 7, 21
//4 has 3 divisors: 1, 2, 4
//7 has 2 divisors: 1, 7
//The answer is the sum of divisors of 21 only.
//Example 2:
//Input: nums = [21,21]
//Output: 64
//Example 3:
//Input: nums = [1,2,3,4,5]
//Output: 0
// 
//Constraints:
//	1 <= nums.length <= 104
//	1 <= nums[i] <= 105
/**
 * @param {number[]} nums
 * @return {number}
 */
var sumFourDivisors = function(nums) {
    const countDivisors = (n) => {
        let count = 0;
        for(let i = 1; i <= Math.sqrt(n); i++) {
            if(n % i === 0) {
                if(n / i === i) {
                    count++;
                } else {
                    count += 2;
                }
            }
        }
        return count;
    };
    
    let sum = 0;
    for(let num of nums) {
        if(countDivisors(num) === 4) {
            sum += num;
        }
    }
    return sum;
    
};
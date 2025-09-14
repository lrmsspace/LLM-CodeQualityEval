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
    let sum = 0;
    for(let i = 0; i < nums.length; i++){
        let count = 0;
        let sumDivisors = 0;
        for(let j = 1; j <= Math.sqrt(nums[i]); j++){
            if(nums[i] % j === 0){
                count++;
                sumDivisors += j;
                if(j !== nums[i] / j){
                    count++;
                    sumDivisors += nums[i] / j;
                }
            }
        }
        if(count === 4){
            sum += sumDivisors + nums[i];
        }
    }
    return sum;
};
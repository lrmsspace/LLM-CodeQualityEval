/**https://leetcode.com/problems/set-mismatch/ */
//You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
//You are given an integer array nums representing the data status of this set after the error.
//Find the number that occurs twice and the number that is missing and return them in the form of an array.
// 
//Example 1:
//Input: nums = [1,2,2,4]
//Output: [2,3]
//Example 2:
//Input: nums = [1,1]
//Output: [1,2]
// 
//Constraints:
//	2 <= nums.length <= 104
//	1 <= nums[i] <= 104
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findErrorNums = function(nums) {
    const n = nums.length;
    const sum = n * (n + 1) / 2;
    const sumOfSquares = n * (n + 1) * (2 * n + 1) / 6;
    
    let twice = 0, missing = 0;
    for (let num of nums) {
        twice += num - 1;
        sumOfSquares -= num * num - 1;
    }
    
    missing = twice - sum + sumOfSquares;
    
    return [twice + 1, missing + 1];
    
};
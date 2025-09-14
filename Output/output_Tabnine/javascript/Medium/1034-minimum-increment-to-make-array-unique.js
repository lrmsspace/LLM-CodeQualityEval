/**https://leetcode.com/problems/minimum-increment-to-make-array-unique/ */
//You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.
//Return the minimum number of moves to make every value in nums unique.
//The test cases are generated so that the answer fits in a 32-bit integer.
// 
//Example 1:
//Input: nums = [1,2,2]
//Output: 1
//Explanation: After 1 move, the array could be [1, 2, 3].
//Example 2:
//Input: nums = [3,2,1,2,1,7]
//Output: 6
//Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
//It can be shown that it is impossible for the array to have all unique values with 5 or less moves.
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 105
/**
 * @param {number[]} nums
 * @return {number}
 */
var minIncrementForUnique = function(nums) {
    let count = new Map();
    let minVal = Infinity;
    let sum = 0;
    
    for (let num of nums) {
        count.set(num, (count.get(num) || 0) + 1);
        minVal = Math.min(minVal, num);
        sum += num;
    }
    
    let moves = 0;
    
    for (let num = minVal; num < sum; num++) {
        if (count.get(num) > 1) {
            moves += count.get(num) - 1;
            count.set(num, 1);
        }
    }
    
    return moves;
    
};
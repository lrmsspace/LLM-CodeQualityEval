/*
 You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.
 Return the minimum number of operations to make all elements of nums divisible by 3.
 Example 1:
 Input: nums = [1,2,3,4]
 Output: 3
 Explanation:
 All array elements can be made divisible by 3 using 3 operations:
 Subtract 1 from 1.
 Add 1 to 2.
 Subtract 1 from 4.
 Example 2:
 Input: nums = [3,6,9]
 Output: 0
 Constraints:
 1 <= nums.length <= 50
 1 <= nums[i] <= 50
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumOperations = function(nums) {
    let sum = nums.reduce((acc, num) => acc + num, 0);
    if (sum % 3!== 0) return -1;
    
    let count = [0, 0, 0];
    for (let num of nums) {
        count[(num - 1) % 3]++;
    }
    
    let minOperations = Math.min(count[0], count[1], count[2]);
    count[1] -= minOperations;
    count[2] -= minOperations;
    
    return minOperations * 2 + Math.max(0, count[1], count[2]);
    
};
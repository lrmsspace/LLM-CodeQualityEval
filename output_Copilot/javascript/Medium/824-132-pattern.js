/**https://leetcode.com/problems/132-pattern/ */
//Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
//Return true if there is a 132 pattern in nums, otherwise, return false.
// 
//Example 1:
//Input: nums = [1,2,3,4]
//Output: false
//Explanation: There is no 132 pattern in the sequence.
//Example 2:
//Input: nums = [3,1,4,2]
//Output: true
//Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
//Example 3:
//Input: nums = [-1,3,2,0]
//Output: true
//Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 2 * 105
//	-109 <= nums[i] <= 109
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var find132pattern = function(nums) {
    let n = nums.length;
    if (n < 3) return false;
    let stack = [];
    let s3 = -Infinity; // s3 is the maximum number in the 132 pattern
    for (let i = n - 1; i >= 0; i--) {
        if (nums[i] < s3) return true; // found a 132 pattern
        while (stack.length && nums[i] > stack[stack.length - 1]) {
            s3 = stack.pop(); // update s3 to the maximum number in the stack
        }
        stack.push(nums[i]); // push the current number to the stack
    }
    return false; // no 132 pattern found    
};
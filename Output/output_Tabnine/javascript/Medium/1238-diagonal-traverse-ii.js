/**https://leetcode.com/problems/diagonal-traverse-ii/ */
//Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.
// 
//Example 1:
//Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,4,2,7,5,3,8,6,9]
//Example 2:
//Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
//Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i].length <= 105
//	1 <= sum(nums[i].length) <= 105
//	1 <= nums[i][j] <= 105
/**
 * @param {number[][]} nums
 * @return {number[]}
 */
var findDiagonalOrder = function(nums) {
    let res = [];
    let m = nums.length;
    if (m === 0) return res;
    let n = nums[0].length;
    let row = 0, col = 0, dir = 1; // 1: right-down, -1: left-up
    
    for (let i = 0; i < m * n; i++) {
        res.push(nums[row][col]);
        if ((row + col) % 2 === 0) { // right-down
            if (col === n - 1) row++;
            else if (row === 0) col++;
            else {
                row--;
                col++;
            }
        } else { // left-up
            if (col === 0) row++;
            else if (row === m - 1) col--;
            else {
                row++;
                col--;
            }
        }
    }
    
    return res;
    
};
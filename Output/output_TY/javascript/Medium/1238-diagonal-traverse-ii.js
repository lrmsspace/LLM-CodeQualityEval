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
    let result = [];
    let map = new Map();
    for(let i=0;i<nums.length;i++){
        for(let j=0;j<nums[i].length;j++){
            let sum = i+j;
            if(map.has(sum)){
                map.set(sum,[...map.get(sum),nums[i][j]]);
            }else{
                map.set(sum,[nums[i][j]]);
            }
        }
    }
    let keys = [...map.keys()].sort((a,b)=>b-a);
    for(let i=0;i<keys.length;i++){
        for(let j=0;j<map.get(keys[i]).length;j++){
            result.push(map.get(keys[i])[j]);
        }
    }
    return result;
};
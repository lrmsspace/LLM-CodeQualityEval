/**https://leetcode.com/problems/majority-element-ii/ */
//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// 
//Example 1:
//Input: nums = [3,2,3]
//Output: [3]
//Example 2:
//Input: nums = [1]
//Output: [1]
//Example 3:
//Input: nums = [1,2]
//Output: [1,2]
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	-109 <= nums[i] <= 109
// 
//Follow up: Could you solve the problem in linear time and in O(1) space?
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
    let map = {};
    let result = [];
    for(let i=0;i<nums.length;i++){
        if(map[nums[i]]){
            map[nums[i]]++;
        }else{
            map[nums[i]] = 1;
        }
    }
    for(let key in map){
        if(map[key]>Math.floor(nums.length/3)){
            result.push(parseInt(key));
        }
    }
    return result;
};
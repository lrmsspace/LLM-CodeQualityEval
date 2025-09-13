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
    let count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 1;
    for(let num of nums){
        if(num == candidate1) count1++;
        else if(num == candidate2) count2++;
        else if(count1 == 0){
            candidate1 = num;
            count1 = 1;
        }
        else if(count2 == 0){
            candidate2 = num;
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
    }
    count1 = 0, count2 = 0;
    for(let num of nums){
        if(num == candidate1) count1++;
        else if(num == candidate2) count2++;
    }
    let result = [];
    if(count1 > nums.length/3) result.push(candidate1);
    if(count2 > nums.length/3) result.push(candidate2);
    return result;
};
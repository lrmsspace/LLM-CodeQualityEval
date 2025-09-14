/**https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/ */
//Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
//In one move, you can increment or decrement an element of the array by 1.
//Test cases are designed so that the answer will fit in a 32-bit integer.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: 2
//Explanation:
//Only two moves are needed (remember each move increments or decrements one element):
//[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
//Example 2:
//Input: nums = [1,10,2,9]
//Output: 16
// 
//Constraints:
//	n == nums.length
//	1 <= nums.length <= 105
//	-109 <= nums[i] <= 109
/**
 * @param {number[]} nums
 * @return {number}
 */
var minMoves2 = function(nums) {
    let sum = 0;
    let n = nums.length;
    let median = 0;
    nums.sort((a,b)=>a-b);
    if(n%2==0){
        median = (nums[n/2]+nums[(n/2)-1])/2;
    }else{
        median = nums[Math.floor(n/2)];
    }
    for(let i=0;i<n;i++){
        sum += Math.abs(median-nums[i]);
    }
    return sum;

};
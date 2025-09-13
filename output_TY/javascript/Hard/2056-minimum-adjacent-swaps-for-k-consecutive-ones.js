/**https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/ */
//You are given an integer array, nums, and an integer k. nums comprises of only 0's and 1's. In one move, you can choose two adjacent indices and swap their values.
//Return the minimum number of moves required so that nums has k consecutive 1's.
// 
//Example 1:
//Input: nums = [1,0,0,1,0,1], k = 2
//Output: 1
//Explanation: In 1 move, nums could be [1,0,0,0,1,1] and have 2 consecutive 1's.
//Example 2:
//Input: nums = [1,0,0,0,0,0,1,1], k = 3
//Output: 5
//Explanation: In 5 moves, the leftmost 1 can be shifted right until nums = [0,0,0,0,0,1,1,1].
//Example 3:
//Input: nums = [1,1,0,1], k = 2
//Output: 0
//Explanation: nums already has 2 consecutive 1's.
// 
//Constraints:
//	1 <= nums.length <= 105
//	nums[i] is 0 or 1.
//	1 <= k <= sum(nums)
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var minMoves = function(nums, k) {
    let n = nums.length;
    let ones = [];
    let sum = 0;
    for(let i=0;i<n;i++){
        if(nums[i]==1){
            ones.push(i);
            sum+=i;
        }
    }
    let ans = Infinity;
    for(let i=0;i<ones.length;i++){
        let mid = ones[i];
        let left = mid-k;
        let right = mid+k;
        let leftSum = left*(left+1)/2;
        let rightSum = right*(right+1)/2;
        let midSum = (mid-left)*(mid-left+1)/2;
    }
    return ans==Infinity?-1:ans;
};
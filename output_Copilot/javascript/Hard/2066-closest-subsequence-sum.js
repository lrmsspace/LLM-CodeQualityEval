/**https://leetcode.com/problems/closest-subsequence-sum/ */
//You are given an integer array nums and an integer goal.
//You want to choose a subsequence of nums such that the sum of its elements is the closest possible to goal. That is, if the sum of the subsequence's elements is sum, then you want to minimize the absolute difference abs(sum - goal).
//Return the minimum possible value of abs(sum - goal).
//Note that a subsequence of an array is an array formed by removing some elements (possibly all or none) of the original array.
// 
//Example 1:
//Input: nums = [5,-7,3,5], goal = 6
//Output: 0
//Explanation: Choose the whole array as a subsequence, with a sum of 6.
//This is equal to the goal, so the absolute difference is 0.
//Example 2:
//Input: nums = [7,-9,15,-2], goal = -5
//Output: 1
//Explanation: Choose the subsequence [7,-9,-2], with a sum of -4.
//The absolute difference is abs(-4 - (-5)) = abs(1) = 1, which is the minimum.
//Example 3:
//Input: nums = [1,2,3], goal = -7
//Output: 7
// 
//Constraints:
//	1 <= nums.length <= 40
//	-107 <= nums[i] <= 107
//	-109 <= goal <= 109
/**
 * @param {number[]} nums
 * @param {number} goal
 * @return {number}
 */
var minAbsDifference = function(nums, goal) {
    const n = nums.length;
    const half = Math.floor(n / 2);
    const leftSums = new Set([0]);
    const rightSums = new Set([0]);

    for (let i = 0; i < half; i++) {
        const newSums = new Set();
        for (const sum of leftSums) {
            newSums.add(sum + nums[i]);
            newSums.add(sum - nums[i]);
        }
        leftSums.clear();
        for (const sum of newSums) {
            leftSums.add(sum);
        }
    }

    for (let i = half; i < n; i++) {
        const newSums = new Set();
        for (const sum of rightSums) {
            newSums.add(sum + nums[i]);
            newSums.add(sum - nums[i]);
        }
        rightSums.clear();
        for (const sum of newSums) {
            rightSums.add(sum);
        }
    }

    let minDiff = Math.abs(goal);
    const rightArray = Array.from(rightSums).sort((a, b) => a - b);

    for (const leftSum of leftSums) {
        const target = goal - leftSum;
        let low = 0;
        let high = rightArray.length - 1;

        while (low <= high) {
            const mid = Math.floor((low + high) / 2);
            const rightSum = rightArray[mid];
            const currentDiff = Math.abs(leftSum + rightSum - goal);

            minDiff = Math.min(minDiff, currentDiff);

            if (rightSum < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return minDiff;    
};
/**https://leetcode.com/problems/split-array-into-consecutive-subsequences/ */
//You are given an integer array nums that is sorted in non-decreasing order.
//Determine if it is possible to split nums into one or more subsequences such that both of the following conditions are true:
//	Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
//	All subsequences have a length of 3 or more.
//Return true if you can split nums according to the above conditions, or false otherwise.
//A subsequence of an array is a new array that is formed from the original array by deleting some (can be none) of the elements without disturbing the relative positions of the remaining elements. (i.e., [1,3,5] is a subsequence of [1,2,3,4,5] while [1,3,2] is not).
// 
//Example 1:
//Input: nums = [1,2,3,3,4,5]
//Output: true
//Explanation: nums can be split into the following subsequences:
//[1,2,3,3,4,5] --> 1, 2, 3
//[1,2,3,3,4,5] --> 3, 4, 5
//Example 2:
//Input: nums = [1,2,3,3,4,4,5,5]
//Output: true
//Explanation: nums can be split into the following subsequences:
//[1,2,3,3,4,4,5,5] --> 1, 2, 3, 4, 5
//[1,2,3,3,4,4,5,5] --> 3, 4, 5
//Example 3:
//Input: nums = [1,2,3,4,4,5]
//Output: false
//Explanation: It is impossible to split nums into consecutive increasing subsequences of length 3 or more.
// 
//Constraints:
//	1 <= nums.length <= 104
//	-1000 <= nums[i] <= 1000
//	nums is sorted in non-decreasing order.
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isPossible = function(nums) {
    let count = new Map();
    let maxCount = 0;
    let sum = 0;
    
    for (let num of nums) {
        count.set(num, (count.get(num) || 0) + 1);
        sum += num;
        maxCount = Math.max(maxCount, count.get(num));
    }
    
    if (sum % 3!== 0) return false;
    
    let target = sum / 3;
    let dp = Array(target + 1).fill(false);
    dp[0] = true;
    
    for (let num of nums) {
        for (let i = target; i >= num; i--) {
            dp[i] = dp[i] || dp[i - num];
        }
    }
    
    if (!dp[target]) return false;
    
    let left = 0;
    let right = 0;
    
    while (right < nums.length) {
        if (count.get(nums[right]) === 0) {
            left = right + 1;
            continue;
        }
        
        if (dp[target - nums[right]]) {
            count.set(nums[right], count.get(nums[right]) - 1);
            target -= nums[right];
            right++;
        } else {
            while (left < right && count.get(nums[left]) > 0) {
                count.set(nums[left], count.get(nums[left]) + 1);
                target += nums[left];
                left++;
            }
            
            if (left === right) return false;
            
            count.set(nums[left], count.get(nums[left]) - 1);
            target -= nums[left];
            left++;
        }
    }
    
    return true;
    
};
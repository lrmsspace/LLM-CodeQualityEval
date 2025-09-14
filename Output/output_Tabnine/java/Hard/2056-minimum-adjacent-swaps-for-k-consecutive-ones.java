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
class Solution {
    public int minMoves(int[] nums, int k) {
        int moves = 0;
        int minVal = Integer.MAX_VALUE;
        int maxVal = Integer.MIN_VALUE;
        int sum = 0;
        
        for (int num : nums) {
            sum += num;
            minVal = Math.min(minVal, num);
            maxVal = Math.max(maxVal, num);
        }
        
        int target = sum - k * (maxVal - minVal);
        
        for (int num : nums) {
            moves += Math.abs(num - target);
        }
        
        return moves / 2; // divide by 2 as we swapped each pair of adjacent indices
        
    }
}
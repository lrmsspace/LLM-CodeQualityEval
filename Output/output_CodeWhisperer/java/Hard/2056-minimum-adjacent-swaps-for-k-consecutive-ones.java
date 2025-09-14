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
import java.util.List;
import java.util.ArrayList;
class Solution {
    public int minMoves(int[] nums, int k) {
        List<Integer> g = new ArrayList<>();
        List<Integer> preSum = new ArrayList<>();
        int n = nums.length;
        preSum.add(0);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                g.add(i - g.size());
                preSum.add(preSum.get(preSum.size() - 1) + g.get(g.size() - 1));
            }
        }
        int m = g.size(), res = Integer.MAX_VALUE;
        for (int i = 0; i <= m - k; i++) {
            int mid = i + k / 2;
            int r = i + k - 1;
            int cost = 0;
            cost = (1 - k % 2) * g.get(mid) + (preSum.get(r + 1) - preSum.get(mid + 1)) - (preSum.get(mid) - preSum.get(i));
            res = Math.min(res, cost);
        }
        return res;       
    }
}
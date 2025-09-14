/**https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/ */
//Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [1], k = 1
//Output: 1
//Example 2:
//Input: nums = [1,2], k = 4
//Output: -1
//Example 3:
//Input: nums = [2,-1,2], k = 3
//Output: 3
// 
//Constraints:
//	1 <= nums.length <= 105
//	-105 <= nums[i] <= 105
//	1 <= k <= 109
class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        int[] prefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        int res = n + 1;
        Deque<Integer> deque = new ArrayDeque<>();
        for (int i = 0; i <= n; i++) {
            while (!deque.isEmpty() && prefixSum[i] - prefixSum[deque.getFirst()] >= k) {
                res = Math.min(res, i - deque.pollFirst());
            }
            while (!deque.isEmpty() && prefixSum[i] <= prefixSum[deque.getLast()]) {
                deque.pollLast();
            }
            deque.addLast(i);
        }
        return res <= n ? res : -1;      
    }
}
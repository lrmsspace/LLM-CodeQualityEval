/**https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/ */
//You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
//We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
// 
//Example 1:
//Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
//Output: [20,24]
//Explanation: 
//List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
//List 2: [0, 9, 12, 20], 20 is in range [20,24].
//List 3: [5, 18, 22, 30], 22 is in range [20,24].
//Example 2:
//Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
//Output: [1,1]
// 
//Constraints:
//	nums.length == k
//	1 <= k <= 3500
//	1 <= nums[i].length <= 50
//	-105 <= nums[i][j] <= 105
//	nums[i] is sorted in non-decreasing order.
class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        int n = nums.size(), left = Integer.MAX_VALUE, right = Integer.MIN_VALUE;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for (int i = 0; i < n; i++) {
            pq.offer(new int[]{nums.get(i).get(0), i, 0});
            right = Math.max(right, nums.get(i).get(0));
        }
        int[] ans = new int[2];
        while (pq.size() == n) {
            int[] cur = pq.poll();
            if (right - cur[0] < right - left) {
                left = cur[0];
                right = right;
                ans[0] = left;
                ans[1] = right;
            }
            if (cur[2] + 1 < nums.get(cur[1]).size()) {
                pq.offer(new int[]{nums.get(cur[1]).get(cur[2] + 1), cur[1], cur[2] + 1});
                right = Math.max(right, nums.get(cur[1]).get(cur[2] + 1));
            }
        }
        return ans;        
    }
}
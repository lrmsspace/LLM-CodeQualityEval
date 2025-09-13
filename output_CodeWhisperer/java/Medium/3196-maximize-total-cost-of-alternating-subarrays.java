/*
 You are given an integer array nums with length n.
 The cost of a subarray nums[l..r], where 0 <= l <= r < n, is defined as:
 cost(l, r) = nums[l] - nums[l + 1] + ... + nums[r] * (−1)r − l
 Your task is to split nums into subarrays such that the total cost of the subarrays is maximized, ensuring each element belongs to exactly one subarray.
 Formally, if nums is split into k subarrays, where k > 1, at indices i1, i2, ..., ik − 1, where 0 <= i1 < i2 < ... < ik - 1 < n - 1, then the total cost will be:
 cost(0, i1) + cost(i1 + 1, i2) + ... + cost(ik − 1 + 1, n − 1)
 Return an integer denoting the maximum total cost of the subarrays after splitting the array optimally.
 Note: If nums is not split into subarrays, i.e. k = 1, the total cost is simply cost(0, n - 1).
 Example 1:
 Input: nums = [1,-2,3,4]
 Output: 10
 Explanation:
 One way to maximize the total cost is by splitting [1, -2, 3, 4] into subarrays [1, -2, 3] and [4]. The total cost will be (1 + 2 + 3) + 4 = 10.
 Example 2:
 Input: nums = [1,-1,1,-1]
 Output: 4
 Explanation:
 One way to maximize the total cost is by splitting [1, -1, 1, -1] into subarrays [1, -1] and [1, -1]. The total cost will be (1 + 1) + (1 + 1) = 4.
 Example 3:
 Input: nums = [0]
 Output: 0
 Explanation:
 We cannot split the array further, so the answer is 0.
 Example 4:
 Input: nums = [1,-1]
 Output: 2
 Explanation:
 Selecting the whole array gives a total cost of 1 + 1 = 2, which is the maximum.
 Constraints:
 1 <= nums.length <= 105
 -109 <= nums[i] <= 109
*/

class Solution {
    public long maximumTotalCost(int[] nums) {
        int n = nums.length;
        long[] dp = new long[n + 1];
        for (int i = 0; i < n; i++) {
            dp[i + 1] = Math.max(dp[i], 0) + nums[i];
        }
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            long diff1 = (long)nums[a[0]] - a[1] + (long)nums[a[2]] - a[3];
            long diff2 = (long)nums[b[0]] - b[1] + (long)nums[b[2]] - b[3];
            return Long.compare(diff2, diff1);
        });
        
        pq.offer(new int[]{0, 0, -1, 0});
        
        for (int j = 1; j < n; j++) {
            while (pq.peek()[2] >= 0 && pq.peek()[2] < j - 1) {
                pq.poll();
            }
            
            int[] cur = pq.peek();
            dp[j + 1] = Math.max(dp[j + 1], dp[cur[2] + 1] + (long)nums[j] - (long)nums[cur[0]] + cur[1] + cur[3]);
            pq.offer(new int[]{j, cur[1] + nums[cur[0]] - nums[j], cur[2], cur[3] + nums[j]});
        }
        
        long res = 0;
        for (int i = 0; i <= n; i++) {
            res = Math.max(res, dp[i]);
        }
        
        return res;
                
    }
}
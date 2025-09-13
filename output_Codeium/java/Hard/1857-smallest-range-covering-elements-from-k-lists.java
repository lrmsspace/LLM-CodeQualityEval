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
        int n = nums.size();
        int[] idx = new int[n];
        int mx = Integer.MIN_VALUE, mn = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            mx = Math.max(mx, nums.get(i).get(0));
            mn = Math.min(mn, nums.get(i).get(0));
        }
        int res = mx - mn, rid = 0;
        while (true) {
            int mx2 = Integer.MIN_VALUE, mn2 = Integer.MAX_VALUE;
            int k = -1;
            for (int i = 0; i < n; i++) {
                mx2 = Math.max(mx2, nums.get(i).get(idx[i]));
                if (idx[i] + 1 < nums.get(i).size()) {
                    mn2 = Math.min(mn2, nums.get(i).get(idx[i] + 1));
                    k = i;
                }
            }
            if (mx2 - mn2 < res) {
                res = mx2 - mn2;
                rid = k;
            }
            if (k == -1) break;
            idx[k]++;
        }
        int[] ans = new int[2];
        ans[0] = mn;
        ans[1] = mx;
        return ans;
    }
}
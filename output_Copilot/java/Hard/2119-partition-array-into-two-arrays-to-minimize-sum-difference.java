/**https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/ */
//You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.
//Return the minimum possible absolute difference.
// 
//Example 1:
//Input: nums = [3,9,7,3]
//Output: 2
//Explanation: One optimal partition is: [3,9] and [7,3].
//The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
//Example 2:
//Input: nums = [-36,36]
//Output: 72
//Explanation: One optimal partition is: [-36] and [36].
//The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.
//Example 3:
//Input: nums = [2,-1,0,4,-2,-9]
//Output: 0
//Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
//The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.
// 
//Constraints:
//	1 <= n <= 15
//	nums.length == 2 * n
//	-107 <= nums[i] <= 107
class Solution {
    public int minimumDifference(int[] nums) {
        int n = nums.length / 2, total = 0, ans = Integer.MAX_VALUE;
        int[] left = new int[1 << n], right = new int[1 << n];
        for (int i = 0; i < n; i++) {
            total += nums[i];
            left[1 << i] = nums[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << i); j++) {
                left[j | (1 << i)] = left[j] + nums[i + n];
            }
        }
        for (int i = 0; i < n; i++) {
            right[1 << i] = nums[i + n];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << i); j++) {
                right[j | (1 << i)] = right[j] + nums[i];
            }
        }
        Arrays.sort(right);
        for (int mask : left) {
            ans = Math.min(ans, Math.abs(total - 2 * mask));
            int idx = Arrays.binarySearch(right, total - mask);
            if (idx < 0) idx = -(idx + 1);
            if (idx > 0) ans = Math.min(ans, Math.abs(total - 2 * (mask + right[idx - 1])));
            if (idx < right.length) ans = Math.min(ans, Math.abs(total - 2 * (mask + right[idx])));
        }
        return ans;        
    }
}
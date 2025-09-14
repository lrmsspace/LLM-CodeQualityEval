/**https://leetcode.com/problems/find-k-th-smallest-pair-distance/ */
//The distance of a pair of integers a and b is defined as the absolute difference between a and b.
//Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.
// 
//Example 1:
//Input: nums = [1,3,1], k = 1
//Output: 0
//Explanation: Here are all the pairs:
//(1,3) -> 2
//(1,1) -> 0
//(3,1) -> 2
//Then the 1st smallest distance pair is (1,1), and its distance is 0.
//Example 2:
//Input: nums = [1,1,1], k = 2
//Output: 0
//Example 3:
//Input: nums = [1,6,1], k = 3
//Output: 5
// 
//Constraints:
//	n == nums.length
//	2 <= n <= 104
//	0 <= nums[i] <= 106
//	1 <= k <= n * (n - 1) / 2
class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int left = 0, right = nums[n - 1] - nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int i = 0, j = 0; i < n; i++) {
                while (j < n && nums[j] - nums[i] <= mid) {
                    j++;
                }
                count += j - i - 1;
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;       
    }
}
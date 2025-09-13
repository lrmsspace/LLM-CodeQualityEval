/**https://leetcode.com/problems/find-all-good-indices/ */
//You are given a 0-indexed integer array nums of size n and a positive integer k.
//We call an index i in the range k <= i < n - k good if the following conditions are satisfied:
//	The k elements that are just before the index i are in non-increasing order.
//	The k elements that are just after the index i are in non-decreasing order.
//Return an array of all good indices sorted in increasing order.
// 
//Example 1:
//Input: nums = [2,1,1,1,3,4,1], k = 2
//Output: [2,3]
//Explanation: There are two good indices in the array:
//- Index 2. The subarray [2,1] is in non-increasing order, and the subarray [1,3] is in non-decreasing order.
//- Index 3. The subarray [1,1] is in non-increasing order, and the subarray [3,4] is in non-decreasing order.
//Note that the index 4 is not good because [4,1] is not non-decreasing.
//Example 2:
//Input: nums = [2,1,1,2], k = 2
//Output: []
//Explanation: There are no good indices in this array.
// 
//Constraints:
//	n == nums.length
//	3 <= n <= 105
//	1 <= nums[i] <= 106
//	1 <= k <= n / 2
class Solution {
    public List<Integer> goodIndices(int[] nums, int k) {
        List<Integer> goodIndices = new ArrayList<>();
        int n = nums.length;
        int[] leftMax = new int[n];
        int[] rightMin = new int[n];
        leftMax[k - 1] = nums[k - 1];
        for (int i = k; i < n; i++) {
            leftMax[i] = Math.max(leftMax[i - 1], nums[i]);
        }
        rightMin[n - k] = nums[n - k];
        for (int i = n - k - 1; i >= 0; i--) {
            rightMin[i] = Math.min(rightMin[i + 1], nums[i]);
        }
        for (int i = k; i < n - k; i++) {
            if (nums[i] >= leftMax[i - 1] && nums[i] <= rightMin[i + 1]) {
                goodIndices.add(i);
            }
        }
        return goodIndices;        
    }
}
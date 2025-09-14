/**https://leetcode.com/problems/sum-of-beauty-in-the-array/ */
//You are given a 0-indexed integer array nums. For each index i (1 <= i <= nums.length - 2) the beauty of nums[i] equals:
//	2, if nums[j] < nums[i] < nums[k], for all 0 <= j < i and for all i < k <= nums.length - 1.
//	1, if nums[i - 1] < nums[i] < nums[i + 1], and the previous condition is not satisfied.
//	0, if none of the previous conditions holds.
//Return the sum of beauty of all nums[i] where 1 <= i <= nums.length - 2.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: 2
//Explanation: For each index i in the range 1 <= i <= 1:
//- The beauty of nums[1] equals 2.
//Example 2:
//Input: nums = [2,4,6,4]
//Output: 1
//Explanation: For each index i in the range 1 <= i <= 2:
//- The beauty of nums[1] equals 1.
//- The beauty of nums[2] equals 0.
//Example 3:
//Input: nums = [3,2,1]
//Output: 0
//Explanation: For each index i in the range 1 <= i <= 1:
//- The beauty of nums[1] equals 0.
// 
//Constraints:
//	3 <= nums.length <= 105
//	1 <= nums[i] <= 105
class Solution {
    public int sumOfBeauties(int[] nums) {
        int sum = 0;
        for (int i = 1; i < nums.length - 1; i++) {
            int leftMax = 0, rightMin = Integer.MAX_VALUE;
            for (int j = 0; j < i; j++) {
                leftMax = Math.max(leftMax, nums[j]);
            }
            for (int j = i + 1; j < nums.length; j++) {
                rightMin = Math.min(rightMin, nums[j]);
            }
            sum += (nums[i] > leftMax && nums[i] < rightMin) ? 2 : (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) ? 1 : 0;
        }
        return sum;
    }
}
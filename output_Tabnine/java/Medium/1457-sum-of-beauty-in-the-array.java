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
        int n = nums.length;
        int sum = 0;
        int[] left = new int[n];
        int[] right = new int[n];
        
        // Find the maximum to the left of each index
        for (int i = 1; i < n; i++) {
            left[i] = Math.max(left[i - 1], nums[i - 1]);
        }
        
        // Find the minimum to the right of each index
        for (int i = n - 2; i >= 0; i--) {
            right[i] = Math.min(right[i + 1], nums[i + 1]);
        }
        
        // Calculate the beauty for each index and add it to the sum
        for (int i = 1; i < n - 1; i++) {
            if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                sum += 2;
            } else if (left[i] < nums[i] && nums[i] < right[i]) {
                sum += 1;
            }
        }
        
        return sum;
        
    }
}
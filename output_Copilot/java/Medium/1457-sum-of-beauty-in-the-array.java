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
        int[] max = new int[n];
        int[] min = new int[n];
        max[0] = nums[0];
        for (int i = 1; i < n; i++) {
            max[i] = Math.max(max[i - 1], nums[i]);
        }
        min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            min[i] = Math.min(min[i + 1], nums[i]);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (max[i - 1] < nums[i] && nums[i] < min[i + 1]) {
                ans += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans += 1;
            }
        }
        return ans;        
    }
}
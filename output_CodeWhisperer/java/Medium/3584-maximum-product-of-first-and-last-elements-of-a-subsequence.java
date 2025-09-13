/*
import java.util.Arrays;
 You are given an integer array nums and an integer m.
 Return the maximum product of the first and last elements of any subsequence of nums of size m.
 Example 1:
 Input: nums = [-1,-9,2,3,-2,-3,1], m = 1
 Output: 81
 Explanation:
 The subsequence [-9] has the largest product of the first and last elements: -9 * -9 = 81. Therefore, the answer is 81.
 Example 2:
 Input: nums = [1,3,-5,5,6,-4], m = 3
 Output: 20
 Explanation:
 The subsequence [-5, 6, -4] has the largest product of the first and last elements.
 Example 3:
 Input: nums = [2,-1,2,-6,5,2,-5,7], m = 2
 Output: 35
 Explanation:
 The subsequence [5, 7] has the largest product of the first and last elements.
 Constraints:
 1 <= nums.length <= 105
 -105 <= nums[i] <= 105
 1 <= m <= nums.length
*/

class Solution {
    public long maximumProduct(int[] nums, int m) {
        Arrays.sort(nums);
        int n = nums.length;
        long max = 1;
        long min = 1;
        if (m == 1) {
            return Math.max(nums[n - 1] * nums[n - 2], nums[0] * nums[1]);
        } else {
            for (int i = n - 1; i >= n - m; i--) {
                max *= nums[i];
                min *= nums[n - i - 1];
            }
            return Math.max(max, min);
        }
            
    }
}
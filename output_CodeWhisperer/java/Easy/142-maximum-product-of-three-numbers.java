/**https://leetcode.com/problems/maximum-product-of-three-numbers/ */
//Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
// 
//Example 1:
//Input: nums = [1,2,3]
//Output: 6
//Example 2:
//Input: nums = [1,2,3,4]
//Output: 24
//Example 3:
//Input: nums = [-1,-2,-3]
//Output: -6
// 
//Constraints:
//	3 <= nums.length <= 104
//	-1000 <= nums[i] <= 1000
class Solution {
    public int maximumProduct(int[] nums) {
        int min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;
        int max1 = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE, max3 = Integer.MIN_VALUE;
        for (int x : nums) {
            if (x <= min1) {
                min2 = min1;
                min1 = x;
            } else if (x <= min2) {     // n lies between min1 and min2
                min2 = x;
            }
            if (x >= max1) {            // x is greater than max1, max2 and max3
                max3 = max2;
                max2 = max1;
                max1 = x;
            } else if (x >= max2) {     // x lies betweem max1 and max2
                max3 = max2;
                max2 = x;
            } else if (x >= max3) {     // x lies betweem max2 and max3
                max3 = x;
            }
        }
        return Math.max(min1 * min2 * max1, max1 * max2 * max3);       
    }
}
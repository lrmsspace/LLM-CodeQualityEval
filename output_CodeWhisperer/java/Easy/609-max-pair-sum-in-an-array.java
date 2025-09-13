/**https://leetcode.com/problems/max-pair-sum-in-an-array/ */
//You are given an integer array nums. You have to find the maximum sum of a pair of numbers from nums such that the largest digit in both numbers is equal.
//For example, 2373 is made up of three distinct digits: 2, 3, and 7, where 7 is the largest among them.
//Return the maximum sum or -1 if no such pair exists.
// 
//Example 1:
//Input: nums = [112,131,411]
//Output: -1
//Explanation:
//Each numbers largest digit in order is [2,3,4].
//Example 2:
//Input: nums = [2536,1613,3366,162]
//Output: 5902
//Explanation:
//All the numbers have 6 as their largest digit, so the answer is 2536 + 3366 = 5902.
//Example 3:
//Input: nums = [51,71,17,24,42]
//Output: 88
//Explanation:
//Each number's largest digit in order is [5,7,7,4,4].
//So we have only two possible pairs, 71 + 17 = 88 and 24 + 42 = 66.
// 
//Constraints:
//	2 <= nums.length <= 100
//	1 <= nums[i] <= 104
class Solution {
    public int maxSum(int[] nums) {
        int max = -1;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int a = nums[i];
                int b = nums[j];
                int maxA = 0;
                int maxB = 0;
                while (a > 0) {
                    maxA = Math.max(maxA, a % 10);
                    a /= 10;
                }
                while (b > 0) {
                    maxB = Math.max(maxB, b % 10);
                    b /= 10;
                }
                if (maxA == maxB) {
                    max = Math.max(max, nums[i] + nums[j]);
                }
            }
        }
        return max;        
    }
}
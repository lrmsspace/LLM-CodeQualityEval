/**https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/ */
//You are given a 0-indexed integer array nums. You can rearrange the elements of nums to any order (including the given order).
//Let prefix be the array containing the prefix sums of nums after rearranging it. In other words, prefix[i] is the sum of the elements from 0 to i in nums after rearranging it. The score of nums is the number of positive integers in the array prefix.
//Return the maximum score you can achieve.
// 
//Example 1:
//Input: nums = [2,-1,0,1,-3,3,-3]
//Output: 6
//Explanation: We can rearrange the array into nums = [2,3,1,-1,-3,0,-3].
//prefix = [2,5,6,5,2,2,-1], so the score is 6.
//It can be shown that 6 is the maximum score we can obtain.
//Example 2:
//Input: nums = [-2,-3,0]
//Output: 0
//Explanation: Any rearrangement of the array will result in a score of 0.
// 
//Constraints:
//	1 <= nums.length <= 105
//	-106 <= nums[i] <= 106
class Solution {
    public int maxScore(int[] nums) {
        int n = nums.length;
        int[] pos = new int[n + 1];
        int[] neg = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            pos[i] = pos[i - 1] + (nums[i - 1] > 0 ? 1 : 0);
            neg[i] = neg[i - 1] + (nums[i - 1] < 0 ? 1 : 0);
        }
        Arrays.sort(nums);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                res = Math.max(res, pos[i + 1] + neg[n] - neg[i + 1]);
            }
        }
        return res;        
    }
}
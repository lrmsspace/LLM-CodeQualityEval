/**https://leetcode.com/problems/maximum-score-of-a-good-subarray/ */
//You are given an array of integers nums (0-indexed) and an integer k.
//The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.
//Return the maximum possible score of a good subarray.
// 
//Example 1:
//Input: nums = [1,4,3,7,4,5], k = 3
//Output: 15
//Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15. 
//Example 2:
//Input: nums = [5,5,4,5,4,1,1,1], k = 0
//Output: 20
//Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 2 * 104
//	0 <= k < nums.length
class Solution {
    public int maximumScore(int[] nums, int k) {
        int n = nums.length;
        int[] leftMin = new int[n];
        leftMin[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = Math.min(leftMin[i-1], nums[i]);
        }
        int[] rightMin = new int[n];
        rightMin[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            rightMin[i] = Math.min(rightMin[i+1], nums[i]);
        }
        int maxScore = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i <= k && k <= j) {
                    maxScore = Math.max(maxScore, Math.min(leftMin[i], rightMin[j]) * (j - i + 1));
                }
            }
        }
        return maxScore;
    }
}
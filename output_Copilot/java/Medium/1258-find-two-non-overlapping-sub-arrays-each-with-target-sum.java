/**https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/ */
//You are given an array of integers arr and an integer target.
//You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.
//Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.
// 
//Example 1:
//Input: arr = [3,2,2,4,3], target = 3
//Output: 2
//Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.
//Example 2:
//Input: arr = [7,3,4,7], target = 7
//Output: 2
//Explanation: Although we have three non-overlapping sub-arrays of sum = 7 ([7], [3,4] and [7]), but we will choose the first and third sub-arrays as the sum of their lengths is 2.
//Example 3:
//Input: arr = [4,3,2,6,2,3,4], target = 6
//Output: -1
//Explanation: We have only one sub-array of sum = 6.
// 
//Constraints:
//	1 <= arr.length <= 105
//	1 <= arr[i] <= 1000
//	1 <= target <= 108
class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        int n = arr.length;
        int[] dp = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        int sum = 0;
        int start = 0;
        int ans = Integer.MAX_VALUE;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            while (sum > target) {
                sum -= arr[start++];
            }
            if (sum == target) {
                if (start > 0 && dp[start - 1] != Integer.MAX_VALUE) {
                    ans = Math.min(ans, dp[start - 1] + i - start + 1);
                }
                min = Math.min(min, i - start + 1);
            }
            dp[i] = min;
        }
        return ans == Integer.MAX_VALUE ? -1 : ans        
    }
}
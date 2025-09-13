/**https://leetcode.com/problems/make-array-strictly-increasing/ */
//Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
//In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
//If there is no way to make arr1 strictly increasing, return -1.
// 
//Example 1:
//Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
//Output: 1
//Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
//Example 2:
//Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
//Output: 2
//Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
//Example 3:
//Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
//Output: -1
//Explanation: You can't make arr1 strictly increasing.
// 
//Constraints:
//	1 <= arr1.length, arr2.length <= 2000
//	0 <= arr1[i], arr2[i] <= 10^9
// 
class Solution {
    public int makeArrayIncreasing(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int m = arr2.length;
        Arrays.sort(arr2);
        int[][] dp = new int[n][m + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = -1;
            }
        }
        dp[0][0] = arr1[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                if (dp[i - 1][j] >= 0) {
                    dp[i][j] = dp[i - 1][j];
                }
                if (j > 0 && dp[i - 1][j - 1] >= 0) {
                    int k = Arrays.binarySearch(arr2, dp[i - 1][j - 1]);
                    if (k < 0) {
                        k = -k - 1;
                    }
                    dp[i][j] = Math.max(dp[i][j], k + j - 1);
                }
            }
        } 
        return dp[n][m];
    }
}
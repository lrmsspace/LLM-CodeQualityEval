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
import java.util.Arrays;
class Solution {
    public int makeArrayIncreasing(int[] arr1, int[] arr2) {
        Arrays.sort(arr2);
  
        int n = arr1.length;
        int m = 0;
        for (int i = 1; i < n; i++) {
            if (arr1[i] <= arr1[i - 1]) {
                m++;
            }
        }
        if (m == 0) {
            return 0;
        }

        int[] dp = new int[m + 1];
        int[] dp2 = new int[m + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int x : arr1) {
            if (x > arr2[0]) {
                break;
            }
            for (int j = m; j > 0; j--) {
                if (x > arr2[j - 1]) {
                    dp2[j] = Math.min(dp2[j], dp[j - 1] + 1);
                }
                if (j < m && arr2[j] > arr2[j - 1]) {
                    dp2[j] = Math.min(dp2[j], dp[j + 1]);
                }
                dp2[j - 1] = dp[j];
                dp[j - 1] = Integer.MAX_VALUE;
            }
            dp = Arrays.copyOf(dp2, m + 1);
            Arrays.fill(dp2, Integer.MAX_VALUE);
        }
        int ans = Arrays.stream(dp).min().getAsInt();

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
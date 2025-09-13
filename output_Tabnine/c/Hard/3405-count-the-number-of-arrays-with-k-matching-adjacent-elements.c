/*
 You are given three integers n, m, k. A good array arr of size n is defined as follows:
 Each element in arr is in the inclusive range [1, m].
 Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].
 Return the number of good arrays that can be formed.
 Since the answer may be very large, return it modulo 109 + 7.
 Example 1:
 Input: n = 3, m = 2, k = 1
 Output: 4
 Explanation:
 There are 4 good arrays. They are [1, 1, 2], [1, 2, 2], [2, 1, 1] and [2, 2, 1].
 Hence, the answer is 4.
 Example 2:
 Input: n = 4, m = 2, k = 2
 Output: 6
 Explanation:
 The good arrays are [1, 1, 1, 2], [1, 1, 2, 2], [1, 2, 2, 2], [2, 1, 1, 1], [2, 2, 1, 1] and [2, 2, 2, 1].
 Hence, the answer is 6.
 Example 3:
 Input: n = 5, m = 2, k = 0
 Output: 2
 Explanation:
 The good arrays are [1, 2, 1, 2, 1] and [2, 1, 2, 1, 2]. Hence, the answer is 2.
 Constraints:
 1 <= n <= 105
 1 <= m <= 105
 0 <= k <= n - 1
*/

int countGoodArrays(int n, int m, int k) {

    // Base cases
    if (n == 1) {
        return m == 1? 1 : 0;
    }
    if (k == 0) {
        return m == 1? 1 : 0;
    }
    
    // Create a prefix sum array to store the frequency of each element
    int[] prefixSum = new int[m + 1];
    prefixSum[0] = 1;
    for (int i = 1; i <= m; i++) {
        prefixSum[i] = (prefixSum[i - 1] * 2) % (1000000007);
    }
    
    // Calculate the number of good arrays for each possible prefix sum
    int[][] dp = new int[n + 1][m + 1];
    dp[1][1] = 1;   
    for (int i = 2; i <= n; i++) {  
        for (int j = 1; j <= m; j++) {
            for (int prevSum = 0; prevSum <= i - k - 1; prevSum++) {
                dp[i][j] = (dp[i][j] + dp[prevSum + 1][j - 1] * prefixSum[j]) % (1000000007);
            }
        }
    }
    return dp[n][m];
    
}
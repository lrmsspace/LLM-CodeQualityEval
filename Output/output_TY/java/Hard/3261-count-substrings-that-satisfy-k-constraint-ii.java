/*
 You are given a binary string s and an integer k.
 You are also given a 2D integer array queries, where queries[i] = [li, ri].
 A binary string satisfies the k-constraint if either of the following conditions holds:
 The number of 0's in the string is at most k.
 The number of 1's in the string is at most k.
 Return an integer array answer, where answer[i] is the number of substrings of s[li..ri] that satisfy the k-constraint.
 Example 1:
 Input: s = "0001111", k = 2, queries = [[0,6]]
 Output: [26]
 Explanation:
 For the query [0, 6], all substrings of s[0..6] = "0001111" satisfy the k-constraint except for the substrings s[0..5] = "000111" and s[0..6] = "0001111".
 Example 2:
 Input: s = "010101", k = 1, queries = [[0,5],[1,4],[2,3]]
 Output: [15,9,3]
 Explanation:
 The substrings of s with a length greater than 3 do not satisfy the k-constraint.
 Constraints:
 1 <= s.length <= 105
 s[i] is either '0' or '1'.
 1 <= k <= s.length
 1 <= queries.length <= 105
 queries[i] == [li, ri]
 0 <= li <= ri < s.length
 All queries are distinct.
*/

class Solution {
    public long[] countKConstraintSubstrings(String s, int k, int[][] queries) {
        
        int n = s.length();

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = s.charAt(i) - 'a';
        }
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = t.charAt(i) - 'a';
        }
        int mod = (int) 1e9 + 7;    
        long[][] dp = new long[n][26];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == 0) {
                    dp[i][j] = (j == b[i] ? 1 : 0);
                } else {
                    dp[i][j] = dp[i - 1][j];
                    if (j == b[i]) dp[i][j]++;
                    dp[i][j] %= mod;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= mod;
            }
        }
        return dp[n - 1][26];
    }
}
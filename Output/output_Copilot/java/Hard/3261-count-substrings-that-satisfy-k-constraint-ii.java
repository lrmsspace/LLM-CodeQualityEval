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
        long[] result = new long[queries.length];
        int[] prefixCount0 = new int[n + 1];
        int[] prefixCount1 = new int[n + 1];

        // Build prefix sums for 0's and 1's
        for (int i = 0; i < n; i++) {
            prefixCount0[i + 1] = prefixCount0[i] + (s.charAt(i) == '0' ? 1 : 0);
            prefixCount1[i + 1] = prefixCount1[i] + (s.charAt(i) == '1' ? 1 : 0);
        }

        // Process each query
        for (int i = 0; i < queries.length; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            long count = 0;

            // Count valid substrings
            for (int j = l; j <= r; j++) {
                for (int k = j; k <= r; k++) {
                    int count0 = prefixCount0[k + 1] - prefixCount0[j];
                    int count1 = prefixCount1[k + 1] - prefixCount1[j];
                    if (count0 <= k && count1 <= k) {
                        count++;
                    }
                }
            }
            result[i] = count;
        }

        return result;
    }
}
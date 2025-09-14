/*
import java.util.Arrays;
 Given a string s, you need to partition it into one or more balanced substrings. For example, if s == "ababcc" then ("abab", "c", "c"), ("ab", "abc", "c"), and ("ababcc") are all valid partitions, but ("a", "bab", "cc"), ("aba", "bc", "c"), and ("ab", "abcc") are not. The unbalanced substrings are bolded.
 Return the minimum number of substrings that you can partition s into.
 Note: A balanced string is a string where each character in the string occurs the same number of times.
 Example 1:
 Input: s = "fabccddg"
 Output: 3
 Explanation:
 We can partition the string s into 3 substrings in one of the following ways: ("fab, "ccdd", "g"), or ("fabc", "cd", "dg").
 Example 2:
 Input: s = "abababaccddb"
 Output: 2
 Explanation:
 We can partition the string s into 2 substrings like so: ("abab", "abaccddb").
 Constraints:
 1 <= s.length <= 1000
 s consists only of English lowercase letters.
*/

class Solution {
    public int minimumSubstringsInPartition(String s) {
        int n = s.length();
        int[] dp = new int[n + 1];
        Arrays.fill(dp, n);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            int[] count = new int[26];
            int maxFreq = 0, distinct = 0;
            for (int j = i; j >= 0; j--) {
                char c = s.charAt(j);
                count[c - 'a']++;
                if (count[c - 'a'] > maxFreq) {
                    maxFreq = count[c - 'a'];
                }
                for (int k = 0; k < 26; k++) {
                    if (count[k] > 0) {
                        distinct++;
                    }
                }
                if (maxFreq * distinct == i - j + 1) {
                    dp[i + 1] = Math.min(dp[i + 1], dp[j] + 1);
                }
            }
        }
        return dp[n];        
    }
}
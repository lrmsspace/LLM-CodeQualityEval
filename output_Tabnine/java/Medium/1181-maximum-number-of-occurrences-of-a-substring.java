/**https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/ */
//Given a string s, return the maximum number of occurrences of any substring under the following rules:
//	The number of unique characters in the substring must be less than or equal to maxLetters.
//	The substring size must be between minSize and maxSize inclusive.
// 
//Example 1:
//Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
//Output: 2
//Explanation: Substring "aab" has 2 occurrences in the original string.
//It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
//Example 2:
//Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
//Output: 2
//Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
// 
//Constraints:
//	1 <= s.length <= 105
//	1 <= maxLetters <= 26
//	1 <= minSize <= maxSize <= min(26, s.length)
//	s consists of only lowercase English letters.
class Solution {
    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        int n = s.length();
        int res = 0;
        for (int i = 0; i <= n - minSize; i++) {
            int[] count = new int[26];
            int uniqueCount = 0;
            for (int j = i; j < i + minSize && j < n; j++) {
                char c = s.charAt(j);
                if (count[c - 'a'] == 0) {
                    uniqueCount++;
                }
                count[c - 'a']++;
                if (uniqueCount > maxLetters) {
                    break;
                }
                res = Math.max(res, j - i + 1);
            }
        }
        return res;
        
    }
}
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
        int[] count = new int[26];
        int[] freq = new int[n + 1];
        int[] freqCount = new int[n + 1];
        int unique = 0;
        int res = 0;
        int maxUnique = 0;
        for (int i = 0; i < n; i++) {
            if (count[s.charAt(i) - 'a']++ == 0) {
                unique++;
            }
            if (i >= minSize) {
                if (--count[s.charAt(i - minSize) - 'a'] == 0) {
                    unique--;
                }
            }
            if (i >= minSize - 1) {
                if (unique <= maxLetters) {
                    int hash = 0;
                    for (int j = i - minSize + 1; j <= i; j++) {
                        hash = hash * 26 + s.charAt(j) - 'a';
                    }
                    freq[hash]++;
                    freqCount[hash]++;
                    if (freqCount[hash] > maxUnique) {
                        maxUnique = freqCount[hash];
                        res = freq[hash];
                    } else if (freqCount[hash] == maxUnique) {
                        res = Math.max(res, freq[hash]);
                    }
                }
            }
        }  
        return res; // Return the maximum number of occurrences of any substring that satisfies the conditions      
    }
}
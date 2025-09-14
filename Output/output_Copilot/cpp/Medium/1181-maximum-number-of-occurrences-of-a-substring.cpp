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
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        int res = 0;
        unordered_map<string, int> cnt;
        unordered_map<char, int> m;
        int unique = 0;
        for (int i = 0; i < n; i++) {
            if (i >= minSize) {
                if (--m[s[i - minSize]] == 0) {
                    unique--;
                }
            }
            if (++m[s[i]] == 1) {
                unique++;
            }
            if (i >= minSize - 1 && unique <= maxLetters) {
                res = max(res, ++cnt[s.substr(i - minSize + 1, minSize)]);
            }
        }
        return res;        
    }
};
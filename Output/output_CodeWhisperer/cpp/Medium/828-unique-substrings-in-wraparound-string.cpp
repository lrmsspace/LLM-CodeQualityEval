/**https://leetcode.com/problems/unique-substrings-in-wraparound-string/ */
//We define the string base to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so base will look like this:
//	"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//Given a string s, return the number of unique non-empty substrings of s are present in base.
// 
//Example 1:
//Input: s = "a"
//Output: 1
//Explanation: Only the substring "a" of s is in base.
//Example 2:
//Input: s = "cac"
//Output: 2
//Explanation: There are two substrings ("a", "c") of s in base.
//Example 3:
//Input: s = "zab"
//Output: 6
//Explanation: There are six substrings ("z", "a", "b", "za", "ab", and "zab") of s in base.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters.
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26, 0);
        int res = 0;
        int len = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && (s[i] - s[i - 1] + 26) % 26 == 1) {
                len++;
            } else {
                len = 1;
            }
            dp[s[i] - 'a'] = max(dp[s[i] - 'a'], len);
        }
        for (int i = 0; i < 26; i++) {
            res += dp[i];
        }
        return res;       
    }
};
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
    public int findSubstringInWraproundString(String s) {
        int n = s.length(), ans = 0;
        int[] dp = new int[26]; // dp[i] means the max length of substring end with char i
        for (int i = 0, len = 0; i < n; i++) {
            if (i > 0 && (s.charAt(i) - s.charAt(i - 1) + 26) % 26 == 1) {
                len++;
            } else {
                len = 1;
            }
            dp[s.charAt(i) - 'a'] = Math.max(dp[s.charAt(i) - 'a'], len);
        }
        for (int i : dp) {
            ans += i;
        }
        return ans;        
    }
}
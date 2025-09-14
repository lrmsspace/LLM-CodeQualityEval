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
int findSubstringInWraproundString(char* s) {
    int len = strlen(s);
    if (len == 0) {
        return 0;
    }
    int dp[26] = {0};
    int count = 1;
    dp[s[0] - 'a'] = 1;
    for (int i = 1; i < len; i++) {
        if (s[i] - s[i - 1] == 1 || s[i - 1] - s[i] == 25) {
            count++;
        } else {
            count = 1;
        }
        dp[s[i] - 'a'] = fmax(dp[s[i] - 'a'], count);
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        res += dp[i];
    }
    return res;    
}
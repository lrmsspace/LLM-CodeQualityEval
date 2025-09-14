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
    int n = strlen(s);
    if (n <= 1) return n;
    
    int dp[26] = {0}; // dp[i] represents the length of the longest substring ending with 'i'
    int maxLen = 0;
    int last = -1;
    
    for (int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        if (last == -1 || (idx - last) % 26 == 1) {
            dp[idx] = max(dp[idx], maxLen + 1);
            maxLen = dp[idx];
        } else {
            maxLen = 1;
        }
        last = idx;
    }
    
    int sum = 0;
    for (int i = 0; i < 26; i++) {
        sum += dp[i];
    }
    return sum;
    
}
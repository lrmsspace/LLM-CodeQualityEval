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
/**
 * @param {string} s
 * @return {number}
 */
var findSubstringInWraproundString = function(s) {
    const n = s.length;
    const dp = new Uint32Array(26).fill(0);
    let last = -1;
    let res = 0;
    for (let i = 0; i < n; i++) {
        const cur = s.charCodeAt(i) - 97;
        if (last >= 0 && (cur - last) % 26 !== 1) dp[cur] = 0;
        last = cur;
        dp[cur] = Math.max(dp[cur], dp[(cur - 1 + 26) % 26] + 1);
        res += dp[cur];
    }
    return res;
};
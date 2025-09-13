/**https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/ */
//Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
//if no such substring exists, return 0.
// 
//Example 1:
//Input: s = "aaabb", k = 3
//Output: 3
//Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
//Example 2:
//Input: s = "ababbc", k = 2
//Output: 5
//Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of only lowercase English letters.
//	1 <= k <= 105
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var longestSubstring = function(s, k) {
    let max = 0;
    for (let i = 0; i < s.length; i++) {
        let count = {};
        for (let j = i; j < s.length; j++) {
            if (!count[s[j]]) {
                count[s[j]] = 1;
            } else {
                count[s[j]]++;
            }
            if (Object.values(count).every(v => v >= k)) {
                max = Math.max(max, j - i + 1);
            }
        }
    }
    return max;
};
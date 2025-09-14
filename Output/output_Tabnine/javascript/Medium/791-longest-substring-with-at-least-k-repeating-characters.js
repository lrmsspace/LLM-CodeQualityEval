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
    let left = 0, right = 0, maxLen = 0;
    let charCount = {};
    
    while (right < s.length) {
        charCount[s[right]] = (charCount[s[right]] || 0) + 1;
        if (Object.values(charCount).filter(count => count < k).length === 0) {
            maxLen = Math.max(maxLen, right - left + 1);
        }
        right++;
        if (charCount[s[left]] === 1) {
            delete charCount[s[left]];
        } else {
            charCount[s[left]]--;
        }
        left++;
    }
    
    return maxLen;
    
};
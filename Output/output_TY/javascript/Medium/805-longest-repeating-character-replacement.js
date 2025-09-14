/**https://leetcode.com/problems/longest-repeating-character-replacement/ */
//You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
//Return the length of the longest substring containing the same letter you can get after performing the above operations.
// 
//Example 1:
//Input: s = "ABAB", k = 2
//Output: 4
//Explanation: Replace the two 'A's with two 'B's or vice versa.
//Example 2:
//Input: s = "AABABBA", k = 1
//Output: 4
//Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
//The substring "BBBB" has the longest repeating letters, which is 4.
//There may exists other ways to achieve this answer too.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only uppercase English letters.
//	0 <= k <= s.length
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var characterReplacement = function(s, k) {
    let max = 0;
    let start = 0;
    let end = 0;
    let maxCount = 0;
    let map = {};
    while(end < s.length){
        let char = s[end];
        map[char] = map[char] ? map[char] + 1 : 1;
        maxCount = Math.max(maxCount, map[char]);
        if(end - start + 1 - maxCount > k){
            map[s[start]]--;
            start++;
        }
        max = Math.max(max, end - start + 1);
        end++;
    }
    return max;
};
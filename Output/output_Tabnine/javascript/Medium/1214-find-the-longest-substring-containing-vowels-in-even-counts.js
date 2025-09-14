/**https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/ */
//Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
// 
//Example 1:
//Input: s = "eleetminicoworoep"
//Output: 13
//Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
//Example 2:
//Input: s = "leetcodeisgreat"
//Output: 5
//Explanation: The longest substring is "leetc" which contains two e's.
//Example 3:
//Input: s = "bcbcbc"
//Output: 6
//Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
// 
//Constraints:
//	1 <= s.length <= 5 x 10^5
//	s contains only lowercase English letters.
/**
 * @param {string} s
 * @return {number}
 */
var findTheLongestSubstring = function(s) {
    const vowels = ['a', 'e', 'i', 'o', 'u'];
    let maxLen = 0;
    let left = 0;
    let count = {};
    
    for (let right = 0; right < s.length; right++) {
        const char = s[right];
        
        if (vowels.includes(char)) {
            count[char] = (count[char] || 0) + 1;
        }
        
        while (Object.values(count).filter(c => c % 2 === 0).length < vowels.length) {
            if (vowels.includes(s[left])) {
                count[s[left]]--;
            }
            left++;
        }
        
        maxLen = Math.max(maxLen, right - left + 1);
    }
    
    return maxLen;
    
};
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
    let res = 0, count = [0, 0, 0, 0, 0], map = {a: 0, e: 1, i: 2, o: 3, u: 4};
    for (let i = 0, j = 0; i < s.length; i++) {
        count[map[s[i]]] ^= 1;
        while (count.includes(1)) count[map[s[j++]]] ^= 1;
        res = Math.max(res, i - j + 1);
    }
    return res;
    
};
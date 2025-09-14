/**https://leetcode.com/problems/count-anagrams/ */
//You are given a string s containing one or more words. Every consecutive pair of words is separated by a single space ' '.
//A string t is an anagram of string s if the ith word of t is a permutation of the ith word of s.
//	For example, "acb dfe" is an anagram of "abc def", but "def cab" and "adc bef" are not.
//Return the number of distinct anagrams of s. Since the answer may be very large, return it modulo 109 + 7.
// 
//Example 1:
//Input: s = "too hot"
//Output: 18
//Explanation: Some of the anagrams of the given string are "too hot", "oot hot", "oto toh", "too toh", and "too oht".
//Example 2:
//Input: s = "aa"
//Output: 1
//Explanation: There is only one anagram possible for the given string.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters and spaces ' '.
//	There is single space between consecutive words.
/**
 * @param {string} s
 * @return {number}
 */
var countAnagrams = function(s) {
    const MOD = 1e9 + 7;
    const n = s.length;
    const freq = new Array(26).fill(0);
    
    for (let i = 0; i < n; i++) {
        freq[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
    }
    
    let ans = 1;
    let factorial = 1;
    
    for (let i = 0; i < 26; i++) {
        ans = (ans * factorial) % MOD;
        factorial = (factorial * freq[i]) % MOD;
    }
    
    return ans;
    
};
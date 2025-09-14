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
var countAnagrams = function(s) {
    const MOD = 1e9 + 7;
    
    function factorial(n) {
        let result = 1;
        for (let i = 2; i <= n; i++) {
            result = (result * i) % MOD;
        }
        return result;
    }
    
    function modInverse(a, m) {
        let m0 = m, t, q;
        let x0 = 0, x1 = 1;
        if (m == 1) return 0;
        while (a > 1) {
            q = Math.floor(a / m);
            t = m;
            m = a % m;
            a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }
        if (x1 < 0) x1 += m0;
        return x1;
    }
    
    const words = s.split(' ');
    let totalAnagrams = 1;
    
    for (const word of words) {
        const freq = {};
        for (const char of word) {
            freq[char] = (freq[char] || 0) + 1;
        }
        
        let wordAnagrams = factorial(word.length);
        for (const count of Object.values(freq)) {
            wordAnagrams = (wordAnagrams * modInverse(factorial(count), MOD)) % MOD;
        }
        
        totalAnagrams = (totalAnagrams * wordAnagrams) % MOD;
    }
    
    return totalAnagrams;
};
};
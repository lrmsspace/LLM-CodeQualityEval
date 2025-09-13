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
    const mod = 1e9 + 7;
    const factorial = [1];
    for (let i = 1; i <= 100000; i++) {
        factorial[i] = (factorial[i - 1] * i) % mod;
    }

    const countAnagramsForWord = (word) => {
        const freq = Array(26).fill(0);
        for (const char of word) {
            freq[char.charCodeAt(0) - 'a'.charCodeAt(0)]++;
        }
        let denominator = 1;
        for (const count of freq) {
            if (count > 1) {
                denominator = (denominator * factorial[count]) % mod;
            }
        }
        return (factorial[word.length] * pow(denominator, mod - 2, mod)) % mod;
    };

    const pow = (base, exp, mod) => {
        let result = 1;
        while (exp > 0) {
            if (exp % 2 === 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp = Math.floor(exp / 2);
        }
        return result;
    };

    const words = s.split(' ');
    let totalAnagrams = 1;

    for (const word of words) {
        totalAnagrams = (totalAnagrams * countAnagramsForWord(word)) % mod;
    }

    return totalAnagrams;    
};
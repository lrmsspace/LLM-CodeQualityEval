/*
 You are given a string s, which is known to be a concatenation of anagrams of some string t.
 Return the minimum possible length of the string t.
 An anagram is formed by rearranging the letters of a string. For example, "aab", "aba", and, "baa" are anagrams of "aab".
 Example 1:
 Input: s = "abba"
 Output: 2
 Explanation:
 One possible string t could be "ba".
 Example 2:
 Input: s = "cdef"
 Output: 4
 Explanation:
 One possible string t could be "cdef", notice that t can be equal to s.
 Example 2:
 Input: s = "abcbcacabbaccba"
 Output: 3
 Constraints:
 1 <= s.length <= 105
 s consist only of lowercase English letters.
*/

/**
 * @param {string} s
 * @return {number}
 */
var minAnagramLength = function(s) {
    let count = new Array(26).fill(0);
    for (let i = 0; i < s.length; i++) {
        count[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
    }
    let ans = Infinity;
    for (let i = 0; i < 26; i++) {
        if (count[i] === 0) continue;
        let j = i + 1;
        while (j < 26 && count[j] > 0) j++;
        ans = Math.min(ans, 2 * (j - i));
    }
    return ans;
    
};
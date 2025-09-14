/*
 You are given a palindromic string s.
 Return the lexicographically smallest palindromic permutation of s.
 Example 1:
 Input: s = "z"
 Output: "z"
 Explanation:
 A string of only one character is already the lexicographically smallest palindrome.
 Example 2:
 Input: s = "babab"
 Output: "abbba"
 Explanation:
 Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.
 Example 3:
 Input: s = "daccad"
 Output: "acddca"
 Explanation:
 Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.
 Constraints:
 1 <= s.length <= 105
 s consists of lowercase English letters.
 s is guaranteed to be palindromic.
*/

/**
 * @param {string} s
 * @return {string}
 */
var smallestPalindrome = function(s) {
    let n = s.length;
    let i = n - 1;
    while (i >= 0 && s[i] >= s[i + 1]) i--;
    
    if (i < 0) return s;
    
    let j = n - 1;
    while (s[i] >= s[j]) j--;
    
    [s[i], s[j]] = [s[j], s[i]];
    
    let left = i + 1;
    let right = n - 1;
    while (left < right) {
        [s[left], s[right]] = [s[right], s[left]];
        left++;
        right--;
    }
    
    return s;   
    
};
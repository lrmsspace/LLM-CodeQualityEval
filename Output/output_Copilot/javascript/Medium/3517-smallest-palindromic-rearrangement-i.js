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
    const charCount = new Array(26).fill(0);
    const n = s.length;

    // Count the occurrences of each character
    for (let i = 0; i < n; i++) {
        charCount[s.charCodeAt(i) - 'a'.charCodeAt(0)]++;
    }

    let leftHalf = '';
    let middleChar = '';

    // Build the left half of the palindrome
    for (let i = 0; i < 26; i++) {
        if (charCount[i] % 2 === 1) {
            middleChar = String.fromCharCode(i + 'a'.charCodeAt(0));
        }
        leftHalf += String.fromCharCode(i + 'a'.charCodeAt(0)).repeat(Math.floor(charCount[i] / 2));
    }

    // Create the right half by reversing the left half
    const rightHalf = leftHalf.split('').reverse().join('');

    // Construct the final palindrome
    return leftHalf + middleChar + rightHalf;    
};
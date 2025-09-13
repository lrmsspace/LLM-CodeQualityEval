/*
 You are given a palindromic string s and an integer k.
 Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.
 Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.
 Example 1:
 Input: s = "abba", k = 2
 Output: "baab"
 Explanation:
 The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
 Lexicographically, "abba" comes before "baab". Since k = 2, the output is "baab".
 Example 2:
 Input: s = "aa", k = 2
 Output: ""
 Explanation:
 There is only one palindromic rearrangement: "aa".
 The output is an empty string since k = 2 exceeds the number of possible rearrangements.
 Example 3:
 Input: s = "bacab", k = 1
 Output: "abcba"
 Explanation:
 The two distinct palindromic rearrangements of "bacab" are "abcba" and "bacab".
 Lexicographically, "abcba" comes before "bacab". Since k = 1, the output is "abcba".
 Constraints:
 1 <= s.length <= 104
 s consists of lowercase English letters.
 s is guaranteed to be palindromic.
 1 <= k <= 106
*/

/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var smallestPalindrome = function(s, k) {

    // Convert the string to a character array
    let chars = Array.from(s);
    
    // Find the index of the first character that is not a palindrome
    let i = chars.length - 1;
    while (i > 0 && chars[i] === chars[i - 1]) {
        i--;
    }
    
    // If no such character exists, return an empty string
    if (i === 0) {
        return "";
    }
    
    // Find the index of the first character that is greater than the previous character
    let j = chars.length - 1;
    while (j > i && chars[j] <= chars[i - 1]) {
        j--;
    }
    
    // Swap the characters at the found indices
    [chars[i - 1], chars[j]] = [chars[j], chars[i - 1]];
    
    // Reverse the substring from the first character to the found index
    reverse(chars, i, chars.length - 1);
    
    // Convert the character array back to a string
    let result = chars.join("");
    
    // If k is greater than the number of distinct palindromic permutations, return an empty string
    if (k > countDistinctPalindromes(result)) {
        return "";
    }
    
    // Count the number of distinct palindromic permutations up to the k-th one
    let count = 1;
    let current = result;
    while (count < k) {
        let next = getNextPalindrome(current);
        current = next;
        count++;
    }
    
    return current;
    
};
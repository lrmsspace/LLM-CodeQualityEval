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
    const half = Math.floor(s.length / 2);
    const left = s.slice(0, half);
    const right = s.slice(s.length - half).split('').reverse().join('');
    const palindromes = new Set([s]);

    // Generate all distinct palindromic permutations
    const generatePalindromes = (l, r) => {
        if (l.length === 0 && r.length === 0) {
            palindromes.add(l + r);
            return;
        }
        if (l.length > 0) {
            generatePalindromes(l.slice(1), r + l[0]);
        }
        if (r.length > 0) {
            generatePalindromes(l + r[0], r.slice(1));
        }
    };
    generatePalindromes(left, right);

    // Sort palindromic permutations lexicographically
    const sortedPalindromes = Array.from(palindromes).sort();

    // Return the k-th smallest palindromic permutation
    return sortedPalindromes[k - 1] || '';
};
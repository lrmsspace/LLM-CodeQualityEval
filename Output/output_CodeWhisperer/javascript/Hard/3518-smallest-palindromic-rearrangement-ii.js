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
    let str = s.split('').sort().join('');
    let len = str.length;
    let mid = Math.floor(len / 2);
    let left = str.slice(0, mid);
    let right = str.slice(mid).split('').reverse().join('');
    let palindromes = [];
    
    function generatePalindromes(left, right, current) {
        if (current.length === len) {
            let palindrome = current.join('');
            if (palindromes.length < k) {
                palindromes.push(palindrome);
            }
            return;
        }
        
        for (let i = 0; i < left.length; i++) {
            current.push(left[i]);
            generatePalindromes(left.slice(0, i) + left.slice(i + 1), right, current);
            current.pop();
        }
        
        for (let i = 0; i < right.length; i++) {
            current.push(right[i]);
            generatePalindromes(left, right.slice(0, i) + right.slice(i + 1), current);
            current.pop();
        }
    }
    
    generatePalindromes(left, right, []);
    
    if (palindromes.length < k) {
        return '';
    } else {
        return palindromes[k - 1];
    }
        
};
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
    const halfLength = Math.floor(s.length / 2);
    const charCount = {};

    for (let i = 0; i < s.length; i++) {
        charCount[s[i]] = (charCount[s[i]] || 0) + 1;
    }

    let half = [];
    let middle = '';

    for (let char in charCount) {
        if (charCount[char] % 2 === 1) {
            if (middle) return ""; // More than one odd character count, cannot form a palindrome
            middle = char;
        }
        half.push(char.repeat(charCount[char] >> 1));
    }

    half.sort();
    const halfString = half.join('');
    const permutations = new Set();

    const generatePermutations = (str, l, r) => {
        if (l === r) {
            permutations.add(str);
        } else {
            for (let i = l; i <= r; i++) {
                str = swap(str, l, i);
                generatePermutations(str, l + 1, r);
                str = swap(str, l, i);
            }
        }
    };

    const swap = (str, i, j) => {
        let arr = str.split('');
        [arr[i], arr[j]] = [arr[j], arr[i]];
        return arr.join('');
    };

    generatePermutations(halfString, 0, halfString.length - 1);

    const sortedPermutations = Array.from(permutations).sort();
    if (k > sortedPermutations.length) return "";

    return sortedPermutations[k - 1] + middle + sortedPermutations[k - 1].split('').reverse().join('');

};
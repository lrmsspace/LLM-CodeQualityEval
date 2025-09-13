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

class Solution {
public:
    string smallestPalindrome(string s, int k) {
        // Find the index of the first character that is not a palindrome
        int i = 0;
        while (i < s.length() && isPalindrome(s, i)) {
            i++;
        }
        // If there are no unpalindromic characters, return an empty string
        if (i == s.length()) {
            return "";
        }
        // Find the index of the next character that is not a palindrome
        int j = i;
        while (j < s.length() && isPalindrome(s, j)) {
            j++;
        }
        // Swap the characters at the indices i and j to make the string a palindrome
        swap(s[i], s[j - 1]);
        // Reverse the substring from index i+1 to the end of the string to make it a palindrome
        reverse(s.begin() + i + 1, s.end());
        // Check if k is within the range of distinct palindromic permutations
        if (k > countDistinctPalindromes(s)) {
            return "";
        }
        // Find the k-th lexicographically smallest palindromic permutation
        return findKthPalindrome(s, k);
    }
};
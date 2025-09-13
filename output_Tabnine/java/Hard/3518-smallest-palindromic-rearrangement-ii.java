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
    public String smallestPalindrome(String s, int k) {

        StringBuilder sb = new StringBuilder(s);
        int n = sb.length();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            if (sb.charAt(i) == sb.charAt(j)) {
                i++;
                j--;
            } else {
                break;
            }
        }
        // If s is already a palindrome, try to reverse the remaining substring
        if (i >= j) {
            reverse(sb, i, n - 1);
            return sb.toString();
        }
        // Find the k-th lexicographically smallest palindromic permutation
        int count = 0;
        for (int left = i; left >= 0; left--) {
            if (sb.charAt(left) < sb.charAt(j)) {
                reverse(sb, left, j);
                count = n - left - 1;
                break;
            }
        }
        // If k is greater than the number of possible rearrangements, return an empty string
        if (count < k) {
            return "";
        }
        // If k is equal to the number of possible rearrangements, reverse the remaining substring
        if (count == k) {
            reverse(sb, i, n - 1);
        }
        return sb.toString();
        
    }
}
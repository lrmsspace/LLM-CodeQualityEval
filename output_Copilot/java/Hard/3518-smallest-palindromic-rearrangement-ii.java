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
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }

        StringBuilder half = new StringBuilder();
        char oddChar = 0;
        int oddCount = 0;

        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                oddChar = (char) (i + 'a');
                oddCount++;
            }
            half.append(String.valueOf((char) (i + 'a')).repeat(count[i] / 2));
        }

        if (oddCount > 1) return "";

        List<String> palindromes = new ArrayList<>();
        generatePalindromes(half.toString(), oddChar, palindromes);

        Collections.sort(palindromes);
        return k <= palindromes.size() ? palindromes.get(k - 1) : "";
            
    }
}
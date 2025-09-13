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
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        string half = "";
        char oddChar = '\0';
        int oddCount = 0;

        for (auto& [c, count] : freq) {
            if (count % 2 == 1) {
                oddCount++;
                oddChar = c;
            }
            half += string(count / 2, c);
        }

        if (oddCount > 1 || (oddCount == 1 && s.length() % 2 == 0)) {
            return ""; // Not possible to form a palindrome
        }

        sort(half.begin(), half.end());
        string palindrome = half;
        if (oddChar != '\0') {
            palindrome += oddChar;
        }
        reverse(half.begin(), half.end());
        palindrome += half;

        if (k > 1) {
            return ""; // Only one distinct palindromic permutation
        }

        return palindrome;
        
    }
};
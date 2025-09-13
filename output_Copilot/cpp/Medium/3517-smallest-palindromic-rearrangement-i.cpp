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

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> count(26, 0);

        // Count frequency of each character
        for (char c : s) {
            count[c - 'a']++;
        }

        // Build the first half of the palindrome
        string half = "";
        char middle = '\0';
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 1) {
                // If odd count, we can use one occurrence as middle
                if (middle == '\0' || i < middle - 'a') {
                    middle = 'a' + i;
                }
            }
            half += string(count[i] / 2, 'a' + i);
        }

        // Form the smallest palindrome
        string smallest = half;
        if (middle != '\0') {
            smallest += middle;
        }
        reverse(half.begin(), half.end());
        smallest += half;

        return smallest;
    }
};
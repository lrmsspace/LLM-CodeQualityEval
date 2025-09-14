/*
 You are given two strings, s and t.
 You can create a new string by selecting a substring from s (possibly empty) and a substring from t (possibly empty), then concatenating them in order.
 Return the length of the longest palindrome that can be formed this way.
 Example 1:
 Input: s = "a", t = "a"
 Output: 2
 Explanation:
 Concatenating "a" from s and "a" from t results in "aa", which is a palindrome of length 2.
 Example 2:
 Input: s = "abc", t = "def"
 Output: 1
 Explanation:
 Since all characters are different, the longest palindrome is any single character, so the answer is 1.
 Example 3:
 Input: s = "b", t = "aaaa"
 Output: 4
 Explanation:
 Selecting "aaaa" from t is the longest palindrome, so the answer is 4.
 Example 4:
 Input: s = "abcde", t = "ecdba"
 Output: 5
 Explanation:
 Concatenating "abc" from s and "ba" from t results in "abcba", which is a palindrome of length 5.
 Constraints:
 1 <= s.length, t.length <= 1000
 s and t consist of lowercase English letters.
*/

class Solution {
public:
    int longestPalindrome(string s, string t) {
        unordered_map<char, int> countS, countT;
        for (char c : s) {
            countS[c]++;
        }
        for (char c : t) {
            countT[c]++;
        }

        int maxLength = 0;
        bool hasOdd = false;

        // Count pairs from both strings
        for (auto& [c, count] : countS) {
            if (countT.count(c)) {
                int pairs = min(count, countT[c]);
                maxLength += pairs * 2;
                if (pairs % 2 == 1) {
                    hasOdd = true; // At least one odd pair found
                }
            }
        }

        // If we have an odd pair, we can add one more character to the palindrome
        if (hasOdd) {
            maxLength++;
        }

        return maxLength;
        
    }
};
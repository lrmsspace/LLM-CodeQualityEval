/*
 You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.
 While there is a '*', do the following operation:
 Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
 Return the lexicographically smallest resulting string after removing all '*' characters.
 Example 1:
 Input: s = "aaba*"
 Output: "aab"
 Explanation:
 We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.
 Example 2:
 Input: s = "abc"
 Output: "abc"
 Explanation:
 There is no '*' in the string.
 Constraints:
 1 <= s.length <= 105
 s consists only of lowercase English letters and '*'.
 The input is generated such that it is possible to delete all '*' characters.
*/

class Solution {
    public String clearStars(String s) {
        StringBuilder result = new StringBuilder();
        int n = s.length();
        int[] count = new int[26]; // Count of each character

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == '*') {
                // Remove the leftmost smallest character
                for (int j = 0; j < 26; j++) {
                    if (count[j] > 0) {
                        count[j]--;
                        break;
                    }
                }
            } else {
                // Add character to result
                result.append(c);
                count[c - 'a']++;
            }
        }

        return result.toString();        
    }
}
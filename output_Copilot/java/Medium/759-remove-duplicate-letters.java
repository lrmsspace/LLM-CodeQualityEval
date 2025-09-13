/**https://leetcode.com/problems/remove-duplicate-letters/ */
//Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
class Solution {
    public String removeDuplicateLetters(String s) {
        int[] lastOccurrence = new int[26];
        boolean[] inResult = new boolean[26];
        StringBuilder result = new StringBuilder();

        // Count the last occurrence of each character
        for (int i = 0; i < s.length(); i++) {
            lastOccurrence[s.charAt(i) - 'a'] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);
            if (inResult[currentChar - 'a']) {
                continue; // Skip if already in result
            }

            // Remove characters from the result if they are greater than the current character
            // and if they appear later in the string
            while (result.length() > 0 && result.charAt(result.length() - 1) > currentChar &&
                    lastOccurrence[result.charAt(result.length() - 1) - 'a'] > i) {
                inResult[result.charAt(result.length() - 1) - 'a'] = false;
                result.deleteCharAt(result.length() - 1);
            }

            // Add current character to result and mark it as included
            result.append(currentChar);
            inResult[currentChar - 'a'] = true;
        }

        return result.toString();        
    }
}
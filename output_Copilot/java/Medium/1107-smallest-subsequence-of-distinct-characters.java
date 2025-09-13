/**https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/ */
//Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
class Solution {
    public String smallestSubsequence(String s) {
        boolean[] inStack = new boolean[26]; // To track if a character is in the stack
        int[] lastOccurrence = new int[26]; // To track the last occurrence of each character

        // Fill lastOccurrence array
        for (int i = 0; i < s.length(); i++) {
            lastOccurrence[s.charAt(i) - 'a'] = i;
        }

        StringBuilder stack = new StringBuilder(); // Stack to build the result

        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);

            // If the character is already in the stack, skip it
            if (inStack[currentChar - 'a']) {
                continue;
            }

            // Remove characters from the stack while they are greater than the current character
            // and they appear later in the string
            while (stack.length() > 0 && stack.charAt(stack.length() - 1) > currentChar && 
                   lastOccurrence[stack.charAt(stack.length() - 1) - 'a'] > i) {
                inStack[stack.charAt(stack.length() - 1) - 'a'] = false;
                stack.deleteCharAt(stack.length() - 1);
            }

            // Add the current character to the stack and mark it as in the stack
            stack.append(currentChar);
            inStack[currentChar - 'a'] = true;
        }

        return stack.toString(); // Convert StringBuilder to String and return it    
    }
}
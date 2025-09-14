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
        int i = 0;
        int j = 0;
        
        while (j < s.length()) {
            if (s.charAt(j) == '*') {
                while (j < s.length() && s.charAt(j) == '*') {
                    j++;
                }
                if (j < s.length()) {
                    i = Math.max(i, j);
                    j++;
                }
            } else {
                s = s.substring(0, i) + s.substring(j);
                i++;
                j++;
            }
        }
        
        return s.substring(0, i);
        
    }
}
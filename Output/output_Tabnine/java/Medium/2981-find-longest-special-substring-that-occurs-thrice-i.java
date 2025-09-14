/*
 You are given a string s that consists of lowercase English letters.
 A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.
 Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.
 A substring is a contiguous non-empty sequence of characters within a string.
 Example 1:
 Input: s = "aaaa"
 Output: 2
 Explanation: The longest special substring which occurs thrice is "aa": substrings "aaaa", "aaaa", and "aaaa".
 It can be shown that the maximum length achievable is 2.
 Example 2:
 Input: s = "abcdef"
 Output: -1
 Explanation: There exists no special substring which occurs at least thrice. Hence return -1.
 Example 3:
 Input: s = "abcaba"
 Output: 1
 Explanation: The longest special substring which occurs thrice is "a": substrings "abcaba", "abcaba", and "abcaba".
 It can be shown that the maximum length achievable is 1.
 Constraints:
 3 <= s.length <= 50
 s consists of only lowercase English letters.
*/

class Solution {
    public int maximumLength(String s) {

        int n = s.length();
        int maxLength = -1;
        
        // Create a boolean array to store the occurrence of each character
        boolean[] hasOccured = new boolean[26];
        
        // Initialize the count of each character to 0
        int count = 0;
        
        // Initialize the start and end indices of the longest special substring
        int start = 0;
        int end = 0;
        int maxStart = 0;   
        int maxEnd = 0;

        // Iterate through the string
        for (int i = 0; i < n; i++) {
            
            // Get the index of the current character
            int index = s.charAt(i) - 'a';
            
            // If the character has not occurred yet, update the count and update the start index
            if (!hasOccured[index]) {
                count++;
                hasOccured[index] = true;
                
                // Update the end index if necessary
                if (count == 3) {
                    end = i;
                    maxLength = Math.max(maxLength, end - start + 1);
                    maxStart = start;
                    maxEnd = end;
                }
            } else {
                
                // If the character has occurred, reset the count, start index, and update the end index
                count = 0;
                hasOccured[index] = false;
                start = i + 1;
            }
        }
        
        // Check if a special substring occurs at least thrice
        if (count >= 3) {
            maxLength = Math.max(maxLength, end - start + 1);
            maxStart = start;
            maxEnd = end;
        }
        
        // Return the length of the longest special substring
        return maxLength == -1? -1 : maxEnd - maxStart + 1;
        // Alternatively, return the maximum length achieved by the algorithm   
        
    }
}
/*
 Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
 Example 1:
 Input: s = "bcbbbcba"
 Output: 4
 Explanation:
 The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
 Example 2:
 Input: s = "aaaa"
 Output: 2
 Explanation:
 The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
 Constraints:
 2 <= s.length <= 100
 s consists only of lowercase English letters.
*/

class Solution {
    public int maximumLengthSubstring(String s) {
        int n = s.length();
        if (n < 2) return n; // If the string is too short, return its length

        int maxLength = 0;
        int[] count = new int[26]; // To count occurrences of each character
        int left = 0;

        for (int right = 0; right < n; right++) {
            count[s.charAt(right) - 'a']++; // Increment the count for the current character

            // If any character exceeds two occurrences, move the left pointer
            while (count[s.charAt(right) - 'a'] > 2) {
                count[s.charAt(left) - 'a']--; // Decrement the count for the left character
                left++; // Move the left pointer to the right
            }

            // Update the maximum length found so far
            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
        
    }
}
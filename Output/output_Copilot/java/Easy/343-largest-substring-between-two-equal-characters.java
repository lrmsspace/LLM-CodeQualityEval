/**https://leetcode.com/problems/largest-substring-between-two-equal-characters/ */
//Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "aa"
//Output: 0
//Explanation: The optimal substring here is an empty substring between the two 'a's.
//Example 2:
//Input: s = "abca"
//Output: 2
//Explanation: The optimal substring here is "bc".
//Example 3:
//Input: s = "cbzxy"
//Output: -1
//Explanation: There are no characters that appear twice in s.
// 
//Constraints:
//	1 <= s.length <= 300
//	s contains only lowercase English letters.
class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int maxLength = -1;
        int[] firstOccurrence = new int[26];
        for (int i = 0; i < firstOccurrence.length; i++) {
            firstOccurrence[i] = -1; // Initialize to -1 to indicate not found
        }

        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);
            int index = currentChar - 'a'; // Convert char to index (0-25)

            if (firstOccurrence[index] == -1) {
                firstOccurrence[index] = i; // Store the first occurrence index
            } else {
                // Calculate the length of the substring between the two occurrences
                int length = i - firstOccurrence[index] - 1;
                maxLength = Math.max(maxLength, length); // Update maxLength if needed
            }
        }

        return maxLength;        
    }
}
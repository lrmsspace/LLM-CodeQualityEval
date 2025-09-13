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

int maximumLengthSubstring(char* s) {
    int maxLength = 0;
    int count[26] = {0}; // To count occurrences of each character
    int left = 0; // Left pointer for the sliding window

    for (int right = 0; s[right] != '\0'; right++) {
        count[s[right] - 'a']++; // Increment the count of the current character

        // If any character occurs more than 2 times, shrink the window from the left
        while (count[s[right] - 'a'] > 2) {
            count[s[left] - 'a']--; // Decrement the count of the left character
            left++; // Move the left pointer to the right
        }

        // Update maxLength if the current window is valid
        maxLength = (right - left + 1 > maxLength) ? (right - left + 1) : maxLength;
    }

    return maxLength;
    
}
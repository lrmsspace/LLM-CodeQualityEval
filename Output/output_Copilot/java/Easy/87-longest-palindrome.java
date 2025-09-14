/**https://leetcode.com/problems/longest-palindrome/ */
//Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
//Letters are case sensitive, for example, "Aa" is not considered a palindrome.
// 
//Example 1:
//Input: s = "abccccdd"
//Output: 7
//Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
//Example 2:
//Input: s = "a"
//Output: 1
//Explanation: The longest palindrome that can be built is "a", whose length is 1.
// 
//Constraints:
//	1 <= s.length <= 2000
//	s consists of lowercase and/or uppercase English letters only.
class Solution {
    public int longestPalindrome(String s) {
        int[] charCount = new int[128]; // ASCII range for lowercase and uppercase letters
        for (char c : s.toCharArray()) {
            charCount[c]++;
        }
        int length = 0;
        boolean hasOddCount = false;
        for (int count : charCount) {
            if (count % 2 == 0) {
                length += count; // Add even counts directly
            } else {
                length += count - 1; // Add odd counts minus one
                hasOddCount = true; // Mark that we have at least one odd count
            }
        }
        return length + (hasOddCount ? 1 : 0); // Add one if there's an odd count to use as the center of the palindrome        
    }
}
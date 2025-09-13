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
        int[] count = new int[52]; // Count the occurrences of lowercase and uppercase letters
        for (char c : s.toCharArray()) {
            if (Character.isLowerCase(c)) {
                count[c - 'a']++;
            } else {
                count[c - 'A' + 26]++;
            }
        }
        
        int ans = 0;
        boolean hasOdd = false;
        
        for (int c : count) {
            ans += c / 2 * 2;
            hasOdd |= c % 2!= 0;
        }
        
        return ans + (hasOdd? 1 : 0);
        
    }
}
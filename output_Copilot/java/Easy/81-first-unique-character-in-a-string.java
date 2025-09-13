/**https://leetcode.com/problems/first-unique-character-in-a-string/ */
//Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
// 
//Example 1:
//Input: s = "leetcode"
//Output: 0
//Explanation:
//The character 'l' at index 0 is the first character that does not occur at any other index.
//Example 2:
//Input: s = "loveleetcode"
//Output: 2
//Example 3:
//Input: s = "aabb"
//Output: -1
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only lowercase English letters.
class Solution {
    public int firstUniqChar(String s) {
        int[] freq = new int[26]; // Array to store frequency of each character

        // Count the frequency of each character in the string
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        // Find the first unique character by checking the frequency array
        for (int i = 0; i < s.length(); i++) {
            if (freq[s.charAt(i) - 'a'] == 1) {
                return i; // Return the index of the first unique character
            }
        }

        return -1; // If no unique character is found, return -1        
    }
}
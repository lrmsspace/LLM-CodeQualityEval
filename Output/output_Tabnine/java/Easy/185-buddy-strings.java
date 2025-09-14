/**https://leetcode.com/problems/buddy-strings/ */
//Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
//Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].
//	For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
// 
//Example 1:
//Input: s = "ab", goal = "ba"
//Output: true
//Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
//Example 2:
//Input: s = "ab", goal = "ab"
//Output: false
//Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
//Example 3:
//Input: s = "aa", goal = "aa"
//Output: true
//Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
// 
//Constraints:
//	1 <= s.length, goal.length <= 2 * 104
//	s and goal consist of lowercase letters.
class Solution {
    public boolean buddyStrings(String s, String goal) {
        if (s.length()!= goal.length()) {
            return false;
        }
        int[] count = new int[26];
        int diff = 0;
        char[] arr = s.toCharArray();
        
        for (int i = 0; i < s.length(); i++) {
            count[arr[i] - 'a']++;
            if (arr[i]!= goal.charAt(i)) {
                diff++;
            }
        }
        
        if (diff!= 2) {
            return false;
        }
        
        for (int i = 0; i < 26; i++) {
            if (count[i] > 1) {
                return true;
            }
        }
        
        return false;
        
    }
}
/**https://leetcode.com/problems/valid-anagram/ */
//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// 
//Example 1:
//Input: s = "anagram", t = "nagaram"
//Output: true
//Example 2:
//Input: s = "rat", t = "car"
//Output: false
// 
//Constraints:
//	1 <= s.length, t.length <= 5 * 104
//	s and t consist of lowercase English letters.
// 
//Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
class Solution {
    public boolean isAnagram(String s, String t) {
if (s.length() != t.length()) {
    return false;
}

int[] charCounts = new int[26];
for (char c : s.toCharArray()) {
    charCounts[c - 'a']++;
}
for (char c : t.toCharArray()) {
    charCounts[c - 'a']--;
    if (charCounts[c - 'a'] < 0) {
        return false;
    }
}
return true;

    }
}
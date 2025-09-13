/**https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/ */
//You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
//Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
// 
//Example 1:
//Input: s1 = "bank", s2 = "kanb"
//Output: true
//Explanation: For example, swap the first character with the last character of s2 to make "bank".
//Example 2:
//Input: s1 = "attack", s2 = "defend"
//Output: false
//Explanation: It is impossible to make them equal with one string swap.
//Example 3:
//Input: s1 = "kelb", s2 = "kelb"
//Output: true
//Explanation: The two strings are already equal, so no string swap operation is required.
// 
//Constraints:
//	1 <= s1.length, s2.length <= 100
//	s1.length == s2.length
//	s1 and s2 consist of only lowercase English letters.
class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        if (s1.equals(s2)) return true; // If they are already equal, return true.
        int n = s1.length(), i = 0, j = n - 1;
        while (i < n && s1.charAt(i) == s2.charAt(i)) i++; // Find the first index where they differ.
        while (j >= 0 && s1.charAt(j) == s2.charAt(j)) j--; // Find the last index where they differ.
        if (i >= j) return false; // If they differ at more than two indices, return false.
        return s1.charAt(i) == s2.charAt(j) && s1.charAt(j) == s2.charAt(i); // Check if swapping makes them equal.        
    }
}
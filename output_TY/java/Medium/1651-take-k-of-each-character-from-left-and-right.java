/**https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/ */
//You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.
//Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.
// 
//Example 1:
//Input: s = "aabaaaacaabc", k = 2
//Output: 8
//Explanation: 
//Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
//Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
//A total of 3 + 5 = 8 minutes is needed.
//It can be proven that 8 is the minimum number of minutes needed.
//Example 2:
//Input: s = "a", k = 1
//Output: -1
//Explanation: It is not possible to take one 'b' or 'c' so return -1.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only the letters 'a', 'b', and 'c'.
//	0 <= k <= s.length
class Solution {
    public int takeCharacters(String s, int k) {
        int[] freq = new int[3];
        for (char c : s.toCharArray()) freq[c - 'a']++;
        if (freq[0] < k || freq[1] < k || freq[2] < k) return -1;

        int left = 0, right = 0, ans = Integer.MAX_VALUE, count = 0;
        while (right < s.length()) {
            freq[s.charAt(right++) - 'a']--;
            while (freq[0] <= k && freq[1] <= k && freq[2] <= k) {
                ans = Math.min(ans, right - left);
                freq[s.charAt(left++) - 'a']++;
            }
        } 
        return ans;   
    }
}
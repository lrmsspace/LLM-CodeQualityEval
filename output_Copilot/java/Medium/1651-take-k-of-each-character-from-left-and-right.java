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
        int[] count = new int[3];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        int n = s.length();
        int ans = n;
        for (int i = 0; i <= n; i++) {
            int[] left = new int[3];
            for (int j = 0; j < i; j++) {
                left[s.charAt(j) - 'a']++;
            }
            int right = n - i;
            for (int j = 0; j < 3; j++) {
                int need = k - Math.min(left[j], count[j] - left[j]);
                if (need > 0) {
                    right -= need;
                }
            }
            if (right >= 0) {
                ans = Math.min(ans, right);
            }
        }
        return ans == n ? -1 : ans;        
    }
}
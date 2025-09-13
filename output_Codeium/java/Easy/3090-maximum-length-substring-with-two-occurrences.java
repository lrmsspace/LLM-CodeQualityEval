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

class Solution {
    public int maximumLengthSubstring(String s) {
        int max_len = 0, i = 0, j = 0;
        int[] counter = new int[26];
        
        while (j < s.length()) {
            if (counter[s.charAt(j) - 'a'] < 2) {
                counter[s.charAt(j) - 'a']++;
                max_len = Math.max(max_len, j - i + 1);
                j++;
            } else {
                counter[s.charAt(i) - 'a']--;
                i++;
            }
        }
        
        return max_len;
    }
}
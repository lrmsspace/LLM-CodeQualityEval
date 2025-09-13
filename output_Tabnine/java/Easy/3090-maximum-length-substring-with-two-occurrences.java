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
        int maxLen = 0;
        int[] count = new int[26];
        
        for (int i = 0, j = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
            
            while (count[s.charAt(i) - 'a'] > 2) {
                count[s.charAt(j) - 'a']--;
                j++;
            }
            
            maxLen = Math.max(maxLen, i - j + 1);
        }
        
        return maxLen;
        
    }
}
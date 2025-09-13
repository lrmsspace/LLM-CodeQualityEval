/**https://leetcode.com/problems/reorganize-string/ */
//Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
// 
//Example 1:
//Input: s = "aab"
//Output: "aba"
//Example 2:
//Input: s = "aaab"
//Output: ""
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of lowercase English letters.
class Solution {
    public String reorganizeString(String s) {
        int[] count = new int[26];
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
        }
        int max = 0, letter = 0;
        for (int i = 0; i < count.length; i++) {
            if (count[i] > max) {
                max = count[i];
                letter = i;
            }
        }
        if (max > (s.length() + 1) / 2) {
            return "";
        }
        char[] res = new char[s.length()];
        int index = 0;
        while (count[letter] > 0) {
            res[index] = (char) (letter + 'a');
            index += 2;
            count[letter]--;
        }
        for (int i = 0; i < count.length; i++) {
            while (count[i] > 0) {
                if (index >= res.length) {
                    index = 1;
                }
                res[index] = (char) (i + 'a');
                index += 2;
                count[i]--;
            }
        }
        return String.valueOf(res);      
    }
}
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
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        int maxCount = 0;
        char maxChar = ' ';
        for (int i = 0; i < 26; i++) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                maxChar = (char) (i + 'a');
            }
        }
        if (maxCount > (s.length() + 1) / 2) {
            return "";
        }
        StringBuilder sb = new StringBuilder();
        while (maxCount > 0) {
            sb.append(maxChar);
            maxCount--;
        }
        count[maxChar - 'a'] = 0;
        for (int i = 0; i < sb.length(); i++) {
            for (int j = 0; j < 26; j++) {
                if (count[j] > 0) {
                    sb.insert(i + 1, (char) (j + 'a'));
                    count[j]--;
                    break;
                }
            }
            i++;
        }
        return sb.toString();        
    }
}
/*
 Given a string s and an integer k, return the total number of substrings of s where at least one character appears at least k times.
 Example 1:
 Input: s = "abacb", k = 2
 Output: 4
 Explanation:
 The valid substrings are:
 "aba" (character 'a' appears 2 times).
 "abac" (character 'a' appears 2 times).
 "abacb" (character 'a' appears 2 times).
 "bacb" (character 'b' appears 2 times).
 Example 2:
 Input: s = "abcde", k = 1
 Output: 15
 Explanation:
 All substrings are valid because every character appears at least once.
 Constraints:
 1 <= s.length <= 3000
 1 <= k <= s.length
 s consists only of lowercase English letters.
*/

class Solution {
    public int numberOfSubstrings(String s, int k) {
        int i = 0, j = 0, ans = 0, n = s.length();
        int[] count = new int[3];
        for (; j < n; j++) {
            count[s.charAt(j) - 'a']++;
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                count[s.charAt(i++) - 'a']--;
            }
            ans += i;
        }
        return ans;
        
    }
}
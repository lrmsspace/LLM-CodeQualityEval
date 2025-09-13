/**https://leetcode.com/problems/repeated-substring-pattern/ */
//Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
// 
//Example 1:
//Input: s = "abab"
//Output: true
//Explanation: It is the substring "ab" twice.
//Example 2:
//Input: s = "aba"
//Output: false
//Example 3:
//Input: s = "abcabcabcabc"
//Output: true
//Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of lowercase English letters.
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int n = s.length();
        for (int i = n / 2; i > 0; i--) {
            if (n % i == 0) {
                String substr = s.substring(0, i);
                boolean match = true;
                for (int j = i; j < n; j += i) {
                    if (!s.substring(j, j + i).equals(substr)) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return true;
                }
            }
        }
        return false;
    }
}
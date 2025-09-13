/**https://leetcode.com/problems/distinct-echo-substrings/ */
//Return the number of distinct non-empty substrings of text that can be written as the concatenation of some string with itself (i.e. it can be written as a + a where a is some string).
// 
//Example 1:
//Input: text = "abcabcabc"
//Output: 3
//Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".
//Example 2:
//Input: text = "leetcodeleetcode"
//Output: 2
//Explanation: The 2 substrings are "ee" and "leetcodeleetcode".
// 
//Constraints:
//	1 <= text.length <= 2000
//	text has only lowercase English letters.
class Solution {
    public int distinctEchoSubstrings(String text) {
        int n = text.length();
        Set<String> set = new HashSet<>();
        for (int len = 1; len <= n / 2; len++) {
            for (int i = 0; i <= n - 2 * len; i++) {
                String s1 = text.substring(i, i + len);
                String s2 = text.substring(i + len, i + 2 * len);
                if (s1.equals(s2)) {
                    set.add(s1);
                }
            }
        }
        return set.size();        
    }
}
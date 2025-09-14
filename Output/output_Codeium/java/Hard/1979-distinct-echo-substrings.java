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
        Set<String> set = new HashSet<>();
        for (int i = 0; i < text.length(); i++) {
            for (int j = i + 1; j < text.length(); j += 2) {
                String s = text.substring(i, j + 1);
                if (s.equals(text.substring(j + 1, s.length() + j + 1))) {
                    set.add(s);
                }
            }
        }
        return set.size();
    }
}
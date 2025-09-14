/**https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/ */
//Given two strings s and t, transform string s into string t using the following operation any number of times:
//	Choose a non-empty substring in s and sort it in place so the characters are in ascending order.
//	
//		For example, applying the operation on the underlined substring in "14234" results in "12344".
//	
//	
//Return true if it is possible to transform s into t. Otherwise, return false.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "84532", t = "34852"
//Output: true
//Explanation: You can transform s into t using the following sort operations:
//"84532" (from index 2 to 3) -> "84352"
//"84352" (from index 0 to 2) -> "34852"
//Example 2:
//Input: s = "34521", t = "23415"
//Output: true
//Explanation: You can transform s into t using the following sort operations:
//"34521" -> "23451"
//"23451" -> "23415"
//Example 3:
//Input: s = "12345", t = "12435"
//Output: false
// 
//Constraints:
//	s.length == t.length
//	1 <= s.length <= 105
//	s and t consist of only digits.
class Solution {
    public boolean isTransformable(String s, String t) {
        int n = s.length(), m = t.length();
        if (n != m) return false;
        int[] freq = new int[10];
        for (int i = 0; i < n; i++) {
            freq[s.charAt(i) - '0']++;
            freq[t.charAt(i) - '0']--;
        }
        for (int f : freq) {
            if (f != 0) return false;
        }
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != t.charAt(i)) {
                char c = s.charAt(i);
                for (int j = i + 1; j < n; j++) {
                    if (s.charAt(j) == c && t.charAt(j) != c) {
                        return false;
                    }
                }
            }
        }
        return true;        
    }
}
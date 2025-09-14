/**https://leetcode.com/problems/last-substring-in-lexicographical-order/ */
//Given a string s, return the last substring of s in lexicographical order.
// 
//Example 1:
//Input: s = "abab"
//Output: "bab"
//Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
//Example 2:
//Input: s = "leetcode"
//Output: "tcode"
// 
//Constraints:
//	1 <= s.length <= 4 * 105
//	s contains only lowercase English letters.
class Solution {
    public String lastSubstring(String s) {
        int n = s.length();
        int maxIndex = 0;
        
        for (int i = 1; i < n; i++) {
            int j = 0;
            while (j < n - i && s.charAt(j) <= s.charAt(j + i)) {
                j++;
            }
            if (j == n - i) {
                maxIndex = i;
            }
        }
        
        return s.substring(maxIndex);
        
    }
}
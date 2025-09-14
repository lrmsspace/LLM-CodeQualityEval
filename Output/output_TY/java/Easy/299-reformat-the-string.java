/**https://leetcode.com/problems/reformat-the-string/ */
//You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).
//You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.
//Return the reformatted string or return an empty string if it is impossible to reformat the string.
// 
//Example 1:
//Input: s = "a0b1c2"
//Output: "0a1b2c"
//Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
//Example 2:
//Input: s = "leetcode"
//Output: ""
//Explanation: "leetcode" has only characters so we cannot separate them by digits.
//Example 3:
//Input: s = "1229857369"
//Output: ""
//Explanation: "1229857369" has only digits so we cannot separate them by characters.
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters and/or digits.
class Solution {
    public String reformat(String s) {
        StringBuilder sb = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();
        for(char c : s.toCharArray()) {
            if(Character.isDigit(c)) {
                sb.append(c);
            } else {
                sb2.append(c);
            }
        }
        if(Math.abs(sb.length() - sb2.length()) > 1) {
            return "";
        }
        StringBuilder sb3 = sb.length() > sb2.length() ? sb : sb2;
        StringBuilder sb4 = sb.length() > sb2.length() ? sb2 : sb;
        StringBuilder sb5 = new StringBuilder();
        while(sb3.length() > 0) {
            sb5.append(sb3.charAt(0));
            sb3.deleteCharAt(0);
            if(sb4.length() > 0) {
                sb5.append(sb4.charAt(0));
                sb4.deleteCharAt(0);
            }
        }
        return sb5.toString();
    }
}
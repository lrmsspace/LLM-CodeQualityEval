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
import java.util.ArrayList;
class Solution {
    public String reformat(String s) {
        StringBuilder sb = new StringBuilder();
        ArrayList<Character> digits = new ArrayList<>();
        ArrayList<Character> letters = new ArrayList<>();
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                digits.add(c);
            } else {
                letters.add(c);
            }
        }
        if (Math.abs(digits.size() - letters.size()) > 1) {
            return "";
        }
        if (digits.size() >= letters.size()) {
            for (int i = 0; i < letters.size(); i++) {
                sb.append(digits.get(i));
                sb.append(letters.get(i));
            }
            if (digits.size() > letters.size()) {
                sb.append(digits.get(digits.size() - 1));
            }
        } else {
            for (int i = 0; i < digits.size(); i++) {
                sb.append(letters.get(i));
                sb.append(digits.get(i));
            }
            sb.append(letters.get(letters.size() - 1));
        }
        return sb.toString();     
    }
}
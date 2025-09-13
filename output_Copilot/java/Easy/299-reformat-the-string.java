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
        int n = s.length(), letterCount = 0, digitCount = 0;
        for (char c : s.toCharArray()) {
            if (Character.isLetter(c)) {
                letterCount++;
            } else {
                digitCount++;
            }
        }

        if (Math.abs(letterCount - digitCount) > 1) {
            return "";
        }

        StringBuilder result = new StringBuilder();
        boolean isLetterNext = letterCount >= digitCount;
        int letterIndex = 0, digitIndex = 0;

        for (int i = 0; i < n; i++) {
            if (isLetterNext) {
                while (letterIndex < n && !Character.isLetter(s.charAt(letterIndex))) {
                    letterIndex++;
                }
                result.append(s.charAt(letterIndex++));
            } else {
                while (digitIndex < n && !Character.isDigit(s.charAt(digitIndex))) {
                    digitIndex++;
                }
                result.append(s.charAt(digitIndex++));
            }
            isLetterNext = !isLetterNext;
        }

        return result.toString();        
    }
}
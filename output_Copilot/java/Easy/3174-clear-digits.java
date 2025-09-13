/*
 You are given a string s.
 Your task is to remove all digits by doing this operation repeatedly:
 Delete the first digit and the closest non-digit character to its left.
 Return the resulting string after removing all digits.
 Note that the operation cannot be performed on a digit that does not have any non-digit character to its left.
 Example 1:
 Input: s = "abc"
 Output: "abc"
 Explanation:
 There is no digit in the string.
 Example 2:
 Input: s = "cb34"
 Output: ""
 Explanation:
 First, we apply the operation on s[2], and s becomes "c4".
 Then we apply the operation on s[1], and s becomes "".
 Constraints:
 1 <= s.length <= 100
 s consists only of lowercase English letters and digits.
 The input is generated such that it is possible to delete all digits.
*/

class Solution {
    public String clearDigits(String s) {
        StringBuilder result = new StringBuilder();
        int lastNonDigitIndex = -1; // To keep track of the last non-digit character index

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                // If we encounter a digit, we check if we can remove it
                if (lastNonDigitIndex != -1) {
                    // Remove the last non-digit character and the current digit
                    result.deleteCharAt(lastNonDigitIndex);
                    lastNonDigitIndex--; // Adjust the index since we removed a character
                }
            } else {
                // If it's a non-digit character, add it to the result
                result.append(c);
                lastNonDigitIndex++;
            }
        }

        return result.toString();
        
    }
}
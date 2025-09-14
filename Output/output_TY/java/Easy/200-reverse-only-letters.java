/**https://leetcode.com/problems/reverse-only-letters/ */
//Given a string s, reverse the string according to the following rules:
//	All the characters that are not English letters remain in the same position.
//	All the English letters (lowercase or uppercase) should be reversed.
//Return s after reversing it.
// 
//Example 1:
//Input: s = "ab-cd"
//Output: "dc-ba"
//Example 2:
//Input: s = "a-bC-dEf-ghIj"
//Output: "j-Ih-gfE-dCba"
//Example 3:
//Input: s = "Test1ng-Leet=code-Q!"
//Output: "Qedo1ct-eeLg=ntse-T!"
// 
//Constraints:
//	1 <= s.length <= 100
//	s consists of characters with ASCII values in the range [33, 122].
//	s does not contain '\"' or '\\'.
class Solution {
    public String reverseOnlyLetters(String s) {
        char[] chars = s.toCharArray();
        int left = 0;
        int right = chars.length - 1;
        while (left < right) {
            while (left < right && !Character.isLetter(chars[left])) {
                left++;
            }
            while (left < right && !Character.isLetter(chars[right])) {
                right--;
            }
            char temp = chars[left];
            chars[left] = chars[right];
            chars[right] = temp;
            left++;
            right--;
        }
        return new String(chars);
    }
}
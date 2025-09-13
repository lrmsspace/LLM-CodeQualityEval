/**https://leetcode.com/problems/decode-string/ */
//Given an encoded string, return its decoded string.
//The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
//You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
//The test cases are generated so that the length of the output will never exceed 105.
// 
//Example 1:
//Input: s = "3[a]2[bc]"
//Output: "aaabcbc"
//Example 2:
//Input: s = "3[a2[c]]"
//Output: "accaccacc"
//Example 3:
//Input: s = "2[abc]3[cd]ef"
//Output: "abcabccdcdcdef"
// 
//Constraints:
//	1 <= s.length <= 30
//	s consists of lowercase English letters, digits, and square brackets '[]'.
//	s is guaranteed to be a valid input.
//	All the integers in s are in the range [1, 300].
class Solution {
    public String decodeString(String s) {
        StringBuilder sb = new StringBuilder();
        int num = 0;
        int n = s.length();
        Stack<Integer> countStack = new Stack<>();
        Stack<String> stringStack = new Stack<>();
        
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push(num);
                stringStack.push(sb.toString());
                num = 0;
                sb.setLength(0); // Clear the StringBuilder
            } else if (c == ']') {
                String prevString = stringStack.pop();
                int count = countStack.pop();
                for (int j = 0; j < count; j++) {
                    prevString += sb.toString();
                }
                sb.setLength(0); // Clear the StringBuilder
                sb.append(prevString);
            } else {
                sb.append(c);
            }
        }
        
        return sb.toString();        
    }
}
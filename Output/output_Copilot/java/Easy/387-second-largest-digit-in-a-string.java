/**https://leetcode.com/problems/second-largest-digit-in-a-string/ */
//Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.
//An alphanumeric string is a string consisting of lowercase English letters and digits.
// 
//Example 1:
//Input: s = "dfa12321afd"
//Output: 2
//Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
//Example 2:
//Input: s = "abc1111"
//Output: -1
//Explanation: The digits that appear in s are [1]. There is no second largest digit. 
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters and digits.
class Solution {
    public int secondHighest(String s) {
        int first = -1, second = -1;
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                int digit = c - '0';
                if (digit > first) {
                    second = first;
                    first = digit;
                } else if (digit > second && digit < first) {
                    second = digit;
                }
            }
        }
        return second;        
    }
}
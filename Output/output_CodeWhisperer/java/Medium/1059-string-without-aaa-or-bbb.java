/**https://leetcode.com/problems/string-without-aaa-or-bbb/ */
//Given two integers a and b, return any string s such that:
//	s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
//	The substring 'aaa' does not occur in s, and
//	The substring 'bbb' does not occur in s.
// 
//Example 1:
//Input: a = 1, b = 2
//Output: "abb"
//Explanation: "abb", "bab" and "bba" are all correct answers.
//Example 2:
//Input: a = 4, b = 1
//Output: "aabaa"
// 
//Constraints:
//	0 <= a, b <= 100
//	It is guaranteed such an s exists for the given a and b.
class Solution {
    public String strWithout3a3b(int a, int b) {
        StringBuilder sb = new StringBuilder();
        int countA = 0, countB = 0;
        while (a > 0 || b > 0) {
            if ((a >= b && countA < 2) || countB == 2) {
                sb.append('a');
                a--;
                countA++;
                countB = 0;
            } else {
                sb.append('b');
                b--;
                countB++;
                countA = 0;
            }
        }
        return sb.toString();       
    }
}
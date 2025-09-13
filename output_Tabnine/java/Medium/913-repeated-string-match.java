/**https://leetcode.com/problems/repeated-string-match/ */
//Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.
//Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".
// 
//Example 1:
//Input: a = "abcd", b = "cdabcdab"
//Output: 3
//Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
//Example 2:
//Input: a = "a", b = "aa"
//Output: 2
// 
//Constraints:
//	1 <= a.length, b.length <= 104
//	a and b consist of lowercase English letters.
class Solution {
    public int repeatedStringMatch(String a, String b) {
        int n = a.length(), m = b.length();
        int left = 1, right = m / n + 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            String temp = a;
            for (int i = 1; i < mid; i++) {
                temp += a;
            }
            if (temp.indexOf(b) >= 0) {
                return mid;
            } else if (temp.indexOf(b) < 0 && mid * n < m) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
        
    }
}
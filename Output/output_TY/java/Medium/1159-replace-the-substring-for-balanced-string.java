/**https://leetcode.com/problems/replace-the-substring-for-balanced-string/ */
//You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.
//A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.
//Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.
// 
//Example 1:
//Input: s = "QWER"
//Output: 0
//Explanation: s is already balanced.
//Example 2:
//Input: s = "QQWE"
//Output: 1
//Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
//Example 3:
//Input: s = "QQQW"
//Output: 2
//Explanation: We can replace the first "QQ" to "ER". 
// 
//Constraints:
//	n == s.length
//	4 <= n <= 105
//	n is a multiple of 4.
//	s contains only 'Q', 'W', 'E', and 'R'.
class Solution {
    public int balancedString(String s) {
        int[] count = new int[128];
        for (char c : s.toCharArray()) count[c]++;
        int n = s.length(), res = n, step = n / 4;
        for (int i = 0, j = 0; i < n; i++) {
            count[s.charAt(i)]--;
            while (j < n && count['Q'] <= step && count['W'] <= step && count['E'] <= step && count['R'] <= step) {
                res = Math.min(res, i - j + 1);
                count[s.charAt(j++)]++;
            }
        }
        return res;

    }
}
/**https://leetcode.com/problems/number-of-ways-to-split-a-string/ */
//Given a binary string s, you can split s into 3 non-empty strings s1, s2, and s3 where s1 + s2 + s3 = s.
//Return the number of ways s can be split such that the number of ones is the same in s1, s2, and s3. Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: s = "10101"
//Output: 4
//Explanation: There are four ways to split s in 3 parts where each part contain the same number of letters '1'.
//"1|010|1"
//"1|01|01"
//"10|10|1"
//"10|1|01"
//Example 2:
//Input: s = "1001"
//Output: 0
//Example 3:
//Input: s = "0000"
//Output: 3
//Explanation: There are three ways to split s in 3 parts.
//"0|0|00"
//"0|00|0"
//"00|0|0"
// 
//Constraints:
//	3 <= s.length <= 105
//	s[i] is either '0' or '1'.
class Solution {
    public int numWays(String s) {
        int n = s.length();
        if (n < 3) {
            return 0;
        }
        int[] ones = new int[n];
        for (int i = 0; i < n; i++) {
            ones[i] = s.charAt(i) == '1' ? 1 : 0;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += ones[i];
        }
        if (count % 3 != 0) {
            return 0;
        }
        if (count == 0) {
            return ((n - 1) * (n - 2) / 2) % 1000000007;
        }
        int ways = 0, first = -1, second = -1, third = -1;
        for (int i = 0; i < n; i++) {
            int val = ones[i];
            if (val == count / 3 && first == -1) {
                first = i;
            } else if (val == count / 3 * 2 && second == -1) {
                second = i;
            } else if (val == count && third == -1) {
                third = i;
            }
            if (second != -1 && third != -1) {
                ways = (ways + (third - second)) % 1000000007;
                second = -1;
                third = -1;
            }
        }
        return ways;
    }
}
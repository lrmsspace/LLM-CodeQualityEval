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
public:
    int numWays(string s) {
        int n = s.size();
        if (n < 3) return 0;
        
        int ones = 0, zeros = 0;
        for (char c : s) {
            ones += c == '1';
            zeros++;
        }
        
        if (ones == 0 || ones == n - ones) return 0;
        
        long long ans = 0;
        long long mod = 1e9 + 7;
        
        // Count the number of ways to split s into three parts with the same number of ones
        for (int i = 1; i < n - 1; i++) {
            if (ones == i) {
                ans = (ans + (zeros - ones) * (zeros - ones - 1) / 2) % mod;
            }
        }
        
        return ans;
        
    }
};
/**https://leetcode.com/problems/number-of-substrings-with-only-1s/ */
//Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: s = "0110111"
//Output: 9
//Explanation: There are 9 substring in total with only 1's characters.
//"1" -> 5 times.
//"11" -> 3 times.
//"111" -> 1 time.
//Example 2:
//Input: s = "101"
//Output: 2
//Explanation: Substring "1" is shown 2 times in s.
//Example 3:
//Input: s = "111111"
//Output: 21
//Explanation: Each substring contains only 1's characters.
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is either '0' or '1'.
class Solution {
public:
    int numSub(string s) {
        const int MOD = 1e9 + 7;
        long long count = 0, result = 0;
        
        for (char c : s) {
            if (c == '1') {
                count++;
                result = (result + count) % MOD;
            } else {
                count = 0;
            }
        }
        
        return result;

    }
};
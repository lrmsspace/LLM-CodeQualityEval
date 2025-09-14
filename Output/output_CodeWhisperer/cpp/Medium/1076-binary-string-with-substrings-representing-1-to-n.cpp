/**https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/ */
//Given a binary string s and a positive integer n, return true if the binary representation of all the integers in the range [1, n] are substrings of s, or false otherwise.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "0110", n = 3
//Output: true
//Example 2:
//Input: s = "0110", n = 4
//Output: false
// 
//Constraints:
//	1 <= s.length <= 1000
//	s[i] is either '0' or '1'.
//	1 <= n <= 109
class Solution {
public:
    bool queryString(string s, int n) {

        for (int i = 1; i <= n; i++) {
            string binary = "";
            int num = i;
            while (num > 0) {
                binary = to_string(num % 2) + binary;
                num /= 2;
            }
            if (s.find(binary) == string::npos) {
                return false;
            }
        }
        return true;
    }
};
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
        unordered_set<string> st;
        for (int i = 1; i <= n; ++i) {
            string t = to_string(i);
            if (s.find(t) == string::npos) return false;
            st.insert(t);
        }
        return true;
        }
};
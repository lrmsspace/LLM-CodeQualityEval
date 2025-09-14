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
        // Initialize a set to store all possible binary representations of numbers from 1 to n
        set<string> binarySet;
        for (int i = 1; i <= n; ++i) {
            binarySet.insert(to_string(i));
        }
        
        // Iterate through the binary string and check if each substring is in the set
        for (int i = 0; i <= s.length() - binarySet.size(); ++i) {
            string substring = s.substr(i, binarySet.size());
            if (binarySet.find(substring) == binarySet.end()) {
                return false;
            }
        }
        
        return true;
        
    }
};
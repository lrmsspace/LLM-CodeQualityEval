/**https://leetcode.com/problems/special-binary-string/ */
//Special binary strings are binary strings with the following two properties:
//	The number of 0's is equal to the number of 1's.
//	Every prefix of the binary string has at least as many 1's as 0's.
//You are given a special binary string s.
//A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.
//Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.
// 
//Example 1:
//Input: s = "11011000"
//Output: "11100100"
//Explanation: The strings "10" [occuring at s[1]] and "1100" [at s[3]] are swapped.
//This is the lexicographically largest string possible after some number of swaps.
//Example 2:
//Input: s = "10"
//Output: "10"
// 
//Constraints:
//	1 <= s.length <= 50
//	s[i] is either '0' or '1'.
//	s is a special binary string.
class Solution {
public:
    string makeLargestSpecial(string s) {
        int n = s.size();
        vector<int> count(n + 1);
        for (int i = 0; i < n; ++i) {
            count[i + 1] = count[i] + (s[i] == '1');
        }
        
        string res;
        for (int i = 0; i < n; ++i) {
            if (count[i] == count[n] - count[i]) {
                res += makeLargestSpecial(s.substr(i + 1, count[n] - count[i] - 1));
                res += '1';
                i += count[n] - count[i] - 1;
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
        
    }
};
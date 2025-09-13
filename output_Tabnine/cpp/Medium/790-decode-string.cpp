/**https://leetcode.com/problems/decode-string/ */
//Given an encoded string, return its decoded string.
//The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
//You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
//The test cases are generated so that the length of the output will never exceed 105.
// 
//Example 1:
//Input: s = "3[a]2[bc]"
//Output: "aaabcbc"
//Example 2:
//Input: s = "3[a2[c]]"
//Output: "accaccacc"
//Example 3:
//Input: s = "2[abc]3[cd]ef"
//Output: "abcabccdcdcdef"
// 
//Constraints:
//	1 <= s.length <= 30
//	s consists of lowercase English letters, digits, and square brackets '[]'.
//	s is guaranteed to be a valid input.
//	All the integers in s are in the range [1, 300].
class Solution {
public:
    string decodeString(string s) {
        stack<pair<char, int>> stk;
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (isdigit(s[i])) {

                int count = 0;
                while (i < n && isdigit(s[i])) {
                    count = count * 10 + s[i++] - '0';
                }
                i--; // Move back to the '['
            } else if (s[i] == '[') {
                stk.push({s[i], count});
                i++;
            } else if (s[i] == ']') {
                string temp = "";
                while (!stk.empty() && stk.top().first!= '[') {
                    temp = stk.top().first + temp;
                    stk.pop();
                }
                stk.pop(); // Pop '['
                int repeatCount = stk.top().second;
                stk.pop();
                string repeatString = stk.top().first + temp;
                stk.pop();
                for (int j = 0; j < repeatCount; j++) {
                    stk.push({repeatString[j], 0});
                }
                i--; // Move back to the '['
            } else {
                stk.push({s[i], 0});
                i++;
            }

        }
        string result = "";
        while (!stk.empty()) {
            result = stk.top().first + result;
            stk.pop();
        }
        return result;
        
    }
};
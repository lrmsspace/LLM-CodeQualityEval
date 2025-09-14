/**https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/ */
//You are given a string s that consists of lower case English letters and brackets.
//Reverse the strings in each pair of matching parentheses, starting from the innermost one.
//Your result should not contain any brackets.
// 
//Example 1:
//Input: s = "(abcd)"
//Output: "dcba"
//Example 2:
//Input: s = "(u(love)i)"
//Output: "iloveu"
//Explanation: The substring "love" is reversed first, then the whole string is reversed.
//Example 3:
//Input: s = "(ed(et(oc))el)"
//Output: "leetcode"
//Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
// 
//Constraints:
//	1 <= s.length <= 2000
//	s only contains lower case English characters and parentheses.
//	It is guaranteed that all parentheses are balanced.
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string cur = "";
        for (char c : s) {
            if (c == '(') {
                st.push(cur);
                cur = "";
            } else if (c == ')') {
                string prev = st.top();
                st.pop();
                reverse(cur.begin(), cur.end());
                cur = prev + cur;
            } else {
                cur += c;
            }
        }
        reverse(cur.begin(), cur.end());
        return cur;
        
    }
};
/**https://leetcode.com/problems/distinct-echo-substrings/ */
//Return the number of distinct non-empty substrings of text that can be written as the concatenation of some string with itself (i.e. it can be written as a + a where a is some string).
// 
//Example 1:
//Input: text = "abcabcabc"
//Output: 3
//Explanation: The 3 substrings are "abcabc", "bcabca" and "cabcab".
//Example 2:
//Input: text = "leetcodeleetcode"
//Output: 2
//Explanation: The 2 substrings are "ee" and "leetcodeleetcode".
// 
//Constraints:
//	1 <= text.length <= 2000
//	text has only lowercase English letters.
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n = text.size();
        unordered_set<string> s;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j += 2) {
                if (j - i > n - j) {
                    break;
                }
                if (text.substr(i, j - i) == text.substr(j, j - i)) {
                    s.insert(text.substr(i, j - i));
                }
            }
        }
        return s.size();        
    }
};
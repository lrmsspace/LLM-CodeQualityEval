/**https://leetcode.com/problems/reformat-the-string/ */
//You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).
//You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.
//Return the reformatted string or return an empty string if it is impossible to reformat the string.
// 
//Example 1:
//Input: s = "a0b1c2"
//Output: "0a1b2c"
//Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
//Example 2:
//Input: s = "leetcode"
//Output: ""
//Explanation: "leetcode" has only characters so we cannot separate them by digits.
//Example 3:
//Input: s = "1229857369"
//Output: ""
//Explanation: "1229857369" has only digits so we cannot separate them by characters.
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters and/or digits.
class Solution {
public:
    string reformat(string s) {
        string a, d;
        for (char c : s) {
            if (isdigit(c)) d.push_back(c);
            else a.push_back(c);
        }
        int diff = a.size() - d.size();
        if (abs(diff) > 1) return "";
        if (diff == 1) return a + d[0];
        if (diff == -1) return d + a[0];
        string res;
        for (int i = 0; i < a.size(); i++) {
            res.push_back(a[i]);
            res.push_back(d[i]);
        }
        return res;       
    }
};
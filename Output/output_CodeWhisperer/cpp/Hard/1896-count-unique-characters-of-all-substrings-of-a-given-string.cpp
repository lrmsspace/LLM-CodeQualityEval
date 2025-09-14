/**https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/ */
//Let's define a function countUniqueChars(s) that returns the number of unique characters in s.
//	For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
//Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.
//Notice that some substrings can be repeated so in this case you have to count the repeated ones too.
// 
//Example 1:
//Input: s = "ABC"
//Output: 10
//Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
//Every substring is composed with only unique letters.
//Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
//Example 2:
//Input: s = "ABA"
//Output: 8
//Explanation: The same as example 1, except countUniqueChars("ABA") = 1.
//Example 3:
//Input: s = "LEETCODE"
//Output: 92
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of uppercase English letters only.
class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<vector<int>> index(26);
        for (int i = 0; i < n; i++) {
            index[s[i] - 'A'].push_back(i);
        }
        int res = 0;
        for (auto& i : index) {
            for (int j = 0; j < i.size(); j++) {
                int left = j == 0 ? -1 : i[j - 1];
                int right = j == i.size() - 1 ? n : i[j + 1];
                res += (i[j] - left) * (right - i[j]);
            }
        }
        return res;     
    }
};
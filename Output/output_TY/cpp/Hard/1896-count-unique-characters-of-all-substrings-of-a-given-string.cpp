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
        int ans = 0;
        vector<int> pre(26, -1);
        vector<int> prePre(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'A';
            ans += (i - pre[c]) * (i - prePre[c]);
            prePre[c] = pre[c];
            pre[c] = i;
        }
        vector<int> post(26, n);
        vector<int> postPost(26, n);
        for (int i = n - 1; i >= 0; i--) {
            intc = s[i] - 'A';
        }
        return ans;
    }
};
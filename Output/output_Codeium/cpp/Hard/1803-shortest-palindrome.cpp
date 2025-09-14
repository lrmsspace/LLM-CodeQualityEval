/**https://leetcode.com/problems/shortest-palindrome/ */
//You are given a string s. You can convert s to a palindrome by adding characters in front of it.
//Return the shortest palindrome you can find by performing this transformation.
// 
//Example 1:
//Input: s = "aacecaaa"
//Output: "aaacecaaa"
//Example 2:
//Input: s = "abcd"
//Output: "dcbabcd"
// 
//Constraints:
//	0 <= s.length <= 5 * 104
//	s consists of lowercase English letters only.
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        string lps = s + "#" + rev;
        vector<int> dp(lps.size(), 0);
        int j = 0;
        for (int i = 1; i < lps.size(); ++i) {
            if (lps[i] == lps[j]) {
                dp[i] = ++j;
            } else if (j > 0) {
                j = dp[j - 1];
                i--;
            }
        }
        string res = rev.substr(0, n - dp.back());
        res += s;
        return res;
    }
};
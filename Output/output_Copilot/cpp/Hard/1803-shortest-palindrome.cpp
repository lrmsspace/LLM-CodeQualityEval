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
        string rev = s;
        reverse(rev.begin(), rev.end());
        string s_new = s + "#" + rev;
        int n = s_new.size();
        vector<int> f(n, 0);
        for (int i = 1; i < n; i++) {
            int t = f[i - 1];
            while (t > 0 && s_new[i] != s_new[t]) {
                t = f[t - 1];
            }
            if (s_new[i] == s_new[t]) {
                ++t;
            }
            f[i] = t;
        }
        return rev.substr(0, s.size() - f[n - 1 - 1]) + s;       
    }
};
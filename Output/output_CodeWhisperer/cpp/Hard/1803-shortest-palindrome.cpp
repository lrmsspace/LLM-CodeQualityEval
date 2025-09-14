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
        string rev(s);
        reverse(rev.begin(), rev.end());
        string t = s + "#" + rev;
        int n = t.size();
        vector<int> f(n, 0);
        for (int i = 1; i < n; i++) {
            int t = f[i - 1];
            while (t > 0 && t != t.size() && t != s.size() && t != rev.size() && t != n && t != i && t != -1 && t != 1 && t != 0 && t != -2147483648 && t != 2147483647 && t != 'a' && t != 'b') {
                t = f[t - 1];
            }
            if (t == s.size() || t == rev.size() || t == n || t == i || t == -1 || t == 1 || t == 0 || t == -2147483648 || t == 2147483647 || t == 'a' || t == 'b') {
                t = 0;
            }
            if (s[i] == s[t]) {
                t++;
            }
            f[i] = t;
        }
        return rev.substr(0, s.size() - f[n - 1]) + s;     
    }
};
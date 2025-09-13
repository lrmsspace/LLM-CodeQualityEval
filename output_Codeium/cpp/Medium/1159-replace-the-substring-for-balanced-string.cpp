/**https://leetcode.com/problems/replace-the-substring-for-balanced-string/ */
//You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.
//A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.
//Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.
// 
//Example 1:
//Input: s = "QWER"
//Output: 0
//Explanation: s is already balanced.
//Example 2:
//Input: s = "QQWE"
//Output: 1
//Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.
//Example 3:
//Input: s = "QQQW"
//Output: 2
//Explanation: We can replace the first "QQ" to "ER". 
// 
//Constraints:
//	n == s.length
//	4 <= n <= 105
//	n is a multiple of 4.
//	s contains only 'Q', 'W', 'E', and 'R'.
class Solution {
public:
    int balancedString(string s) {
        int n = s.length(), res = n;
        vector<int> cnt(128, 0);
        for (int i = 0; i < n; ++i) ++cnt[s[i]];
        int need = n / 4;
        for (int i = 0; i < n; ++i) {
            if (cnt['Q'] > need || cnt['W'] > need || cnt['E'] > need || cnt['R'] > need) {
                int j = i;
                while (cnt['Q'] > need || cnt['W'] > need || cnt['E'] > need || cnt['R'] > need) {
                    --cnt[s[j]];
                    ++j;
                }
                res = min(res, j - i);
            }
        }
        return res;
    }
};
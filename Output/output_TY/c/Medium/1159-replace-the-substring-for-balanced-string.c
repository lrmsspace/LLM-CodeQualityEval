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
int balancedString(char * s){
    int n = strlen(s), i, j, k, l, cnt[4] = {0}, ans = n;
    for (i = 0; i < n / 4; i++) cnt[s[i] - 'Q']++;
    for (i = 0; i < n / 4; i++) {
        for (j = n / 2; j < n; j++) {
            cnt[s[j] - 'Q']--;
            for (k = 0; k < 4; k++) {
                if (cnt[k] != 0) break;
            }
        }
    }
    for (i = 0; i < n / 2; i++) {
        for (j = n / 2; j < n; j++) {
            if (s[i] != s[j]) {
                cnt[s[i] - 'Q']--;
                cnt[s[j] - 'Q']++;
                ans = min(ans, j - i - 1);
            }
        }
    }
    return ans;
}
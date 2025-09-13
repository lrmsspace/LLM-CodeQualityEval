/**https://leetcode.com/problems/valid-permutations-for-di-sequence/ */
//You are given a string s of length n where s[i] is either:
//	'D' means decreasing, or
//	'I' means increasing.
//A permutation perm of n + 1 integers of all the integers in the range [0, n] is called a valid permutation if for all valid i:
//	If s[i] == 'D', then perm[i] > perm[i + 1], and
//	If s[i] == 'I', then perm[i] < perm[i + 1].
//Return the number of valid permutations perm. Since the answer may be large, return it modulo 109 + 7.
// 
//Example 1:
//Input: s = "DID"
//Output: 5
//Explanation: The 5 valid permutations of (0, 1, 2, 3) are:
//(1, 0, 3, 2)
//(2, 0, 3, 1)
//(2, 1, 3, 0)
//(3, 0, 2, 1)
//(3, 1, 2, 0)
//Example 2:
//Input: s = "D"
//Output: 1
// 
//Constraints:
//	n == s.length
//	1 <= n <= 200
//	s[i] is either 'I' or 'D'.
class Solution {
public:
    int numPermsDISequence(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i - 1] == 'D') {
                    dp[i][j] = (j > 0 ? dp[i - 1][j - 1] : 0) - dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] - (j < i ? dp[i - 1][j + 1] : 0);
                }
            }
        }
        return (dp[n][0] + dp[n][1]) % 1000000007;
    }
};
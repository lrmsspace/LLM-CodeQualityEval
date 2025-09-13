/**https://leetcode.com/problems/number-of-beautiful-partitions/ */
//You are given a string s that consists of the digits '1' to '9' and two integers k and minLength.
//A partition of s is called beautiful if:
//	s is partitioned into k non-intersecting substrings.
//	Each substring has a length of at least minLength.
//	Each substring starts with a prime digit and ends with a non-prime digit. Prime digits are '2', '3', '5', and '7', and the rest of the digits are non-prime.
//Return the number of beautiful partitions of s. Since the answer may be very large, return it modulo 109 + 7.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "23542185131", k = 3, minLength = 2
//Output: 3
//Explanation: There exists three ways to create a beautiful partition:
//"2354 | 218 | 5131"
//"2354 | 21851 | 31"
//"2354218 | 51 | 31"
//Example 2:
//Input: s = "23542185131", k = 3, minLength = 3
//Output: 1
//Explanation: There exists one way to create a beautiful partition: "2354 | 218 | 5131".
//Example 3:
//Input: s = "3312958", k = 3, minLength = 1
//Output: 1
//Explanation: There exists one way to create a beautiful partition: "331 | 29 | 58".
// 
//Constraints:
//	1 <= k, minLength <= s.length <= 1000
//	s consists of the digits '1' to '9'.
class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        
        int n = s.length();
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= k; i++) {
            int sum = 0;
            for (int j = minLength * i; j <= n - (k - i); j++) {
                if (j >= minLength * i) {
                    sum = (sum + dp[i - 1][j - minLength]) % 1000000007;
                }
                if (j == n || (s[j] != '2' && s[j] != '3' && s[j] != '5' && s[j] != '7')) {
                    dp[i][j] = sum;
                }
            }
        }
        return dp[k][n];
    }
};